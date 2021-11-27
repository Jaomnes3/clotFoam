
/******************************************************************************
Calculate shear stress by multiplying the dynamic viscocity with two times the 
symmetric part of the local velocity gradient. The magniture of the tensor is 
then calculated and this scalar is used in a power-law approximation to 
estimate the contribution on shear to platelet activation.
******************************************************************************/

Info<< "\nCalculating mechanical activation\n" << endl;

volTensorField tauTensor = nu*rho*fvc::grad(U);
tauTensor += tauTensor.T();

forAll(tau, cellI)
{
    tau[cellI] = tauTensor[cellI].xx()*tauTensor[cellI].xx() + tauTensor[cellI].yy()*tauTensor[cellI].yy() + tauTensor[cellI].zz()*tauTensor[cellI].zz() - tauTensor[cellI].xx()*tauTensor[cellI].yy() - tauTensor[cellI].xx()*tauTensor[cellI].zz() - tauTensor[cellI].yy()*tauTensor[cellI].zz() + 3.0*(tauTensor[cellI].xy()*tauTensor[cellI].xy() + tauTensor[cellI].xz()*tauTensor[cellI].xz() + tauTensor[cellI].yz()*tauTensor[cellI].yz());
    
    tau[cellI] = Foam::sqrt(tau[cellI]/3.0);
}  

Info<< "Max/min shear stress: " << max(tau).value() << "/" << min(tau).value() << nl << endl;

//phi_f = phi_a/(phi_a + phi_n);    //Fraction of activated platelets

//forAll(A_M, cellI)
//{
//    A_M[cellI] = Foam::pow(C.value(), 1.0/beta.value())*beta.value()*Foam::pow(phi_f[cellI], (beta.value() - 1.0)/beta.value())*Foam::pow(tau[cellI], alpha.value()/beta.value());
//}

//Info<< "Max/min A_M: " << max(A_M).value() << "/" << min(A_M).value() << nl << endl;

/******************************************************************************
The activation of platelets due to the activity of ADP is quantified. 
A threshold ADP concentration must be achieved before the activation begins.
******************************************************************************/
Info<< "\nCalculating chemical activation\n" << endl;

forAll(F_switch, cellI)
{
    if(tau[cellI] < shearThreshold.value())
        F_switch[cellI] = 0.0;
    else
        F_switch[cellI] = 1.0;
}

forAll(kpa, cellI)
{
    omega[cellI] = (APR[cellI]/2.0 + APS[cellI]/0.6 + TRB[cellI]/0.1)*F_switch[cellI];
    kpa[cellI] = omega[cellI]/TACT.value();
}

// forAll(A_C, i)
// {
//     if(ADP[i] < ADP_t.value())
//         A_C[i] = 0.0;
//     else
//         A_C[i] = ADP[i]/ADP_t.value()/t_ADP.value();
// }

Info<< "Max/min A_C: " << max(A_C).value() << "/" << min(A_C).value() << nl << endl;

forAll(gamma, i)
{
    gamma[i] = K1_T.value()*H.value()*ATIII[i]/(alpha.value()*KAT.value()*KT.value()+alpha.value()*KAT.value()*beta.value()*TRB[i]+ATIII[i]*beta.value()*TRB[i]);
} 

/******************************************************************************
Solve the 7 species equations.
******************************************************************************/

//Inactivated platelets
Info<< "\nSolving non-activated platelet equation" << endl;
solve(fvm::ddt(RP) + fvm::div(phi, RP) == fvm::laplacian(D_RP, RP) - kpa*RP);
Info<< "Max/min non-activated platelets: " << max(RP).value() << "/" << min(RP).value() << nl << endl;

//Activated platelets
Info<< "\nSolving activated platelet equation" << endl;
solve(fvm::ddt(AP) + fvm::div(phi, AP) == fvm::laplacian(D_AP, AP) + kpa*RP);
Info<< "Max/min activated platelets: " << max(AP).value() << "/" << min(AP).value() << nl << endl;

//Platelet-released agonists
Info<< "\nSolving platelet-released agonist equation" << endl;
solve(fvm::ddt(APR) + fvm::div(phi, APR) == fvm::laplacian(D_APR, APR) + lambda_j*kpa*RP-k1_j*APR);
Info<< "Max/min platelet-released agonists: " << max(APR).value() << "/" << min(APR).value() << nl << endl;

//Platelet-synthesized agonists
Info<< "\nSolving platelet-synthesized agonist equation" << endl;
solve(fvm::ddt(APS) + fvm::div(phi, APS) == fvm::laplacian(D_APS, APS) + spj*AP - k1_j*APS);
Info<< "Max/min platelet-synthesized agonists: " << max(APS).value() << "/" << min(APS).value() << nl << endl;

//Prothrombin
Info<< "\nSolving prothrombin equation" << endl;
solve(fvm::ddt(PT) + fvm::div(phi, PT) == fvm::laplacian(D_PT, PT) - beta*PT*(phi_at*AP + phi_rt*RP));
Info<< "Max/min prothrombin: " << max(PT).value() << "/" << min(PT).value() << nl << endl;

//Thrombin
Info<< "\nSolving thrombin equation" << endl;
solve(fvm::ddt(TRB) + fvm::div(phi, TRB) == fvm::laplacian(D_TRB, TRB) - gamma*TRB + PT*(phi_at*AP + phi_rt*RP));
Info<< "Max/min thrombin: " << max(TRB).value() << "/" << min(TRB).value() << nl << endl;

//Antithrombin III
Info<< "\nSolving antithrombin III equation" << endl;
solve(fvm::ddt(ATIII) + fvm::div(phi, ATIII) == fvm::laplacian(D_ATIII, ATIII) - gamma*beta*TRB);
Info<< "Max/min antithrombin III: " << max(ATIII).value() << "/" << min(ATIII).value() << nl << endl;
