Info<< "Reading field p\n" << endl;
volScalarField p
(
    IOobject
    (
        "p",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);


Info<< "Reading field U\n" << endl;
volVectorField U
(
    IOobject
    (
        "U",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field RP\n" << endl;
volScalarField RP
(
    IOobject
    (
        "RP",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);


Info<< "Reading field AP\n" << endl;
volScalarField AP
(
    IOobject
    (
        "AP",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);


Info<< "Reading field APR\n" << endl;
volScalarField APR
(
    IOobject
    (
        "APR",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field APS\n" << endl;
volScalarField APS
(
    IOobject
    (
        "APS",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field PT\n" << endl;
volScalarField PT
(
    IOobject
    (
        "PT",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);


Info<< "Reading field TRB\n" << endl;
volScalarField TRB
(
    IOobject
    (
        "TRB",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field ATIII\n" << endl;
volScalarField ATIII
(
    IOobject
    (
        "ATIII",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);


Info<< "Reading field omega\n" << endl;
volScalarField omega
(
    IOobject
    (
        "omega",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field F_switch\n" << endl;
volScalarField F_switch
(
    IOobject
    (
        "F_switch",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field kpa\n" << endl;
volScalarField kpa
(
    IOobject
    (
        "kpa",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field gamma\n" << endl;
volScalarField gamma
(
    IOobject
    (
        "gamma",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field JR\n" << endl;
volScalarField JR
(
    IOobject
    (
        "JR",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field JA\n" << endl;
volScalarField JA
(
    IOobject
    (
        "JA",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field JPR\n" << endl;
volScalarField JPR
(
    IOobject
    (
        "JPR",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field JPS\n" << endl;
volScalarField JPS
(
    IOobject
    (
        "JPS",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field JPT\n" << endl;
volScalarField JPT
(
    IOobject
    (
        "JPT",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field JT\n" << endl;
volScalarField JT
(
    IOobject
    (
        "JT",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field Saturation Function\n" << endl;
volScalarField saturationFunction
(
    IOobject
    (
        "saturationFunction",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field M\n" << endl;
volScalarField M
(
    IOobject
    (
        "M",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field MAS\n" << endl;
volScalarField MAS
(
    IOobject
    (
        "MAS",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field MR\n" << endl;
volScalarField MR
(
    IOobject
    (
        "MR",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field MAT\n" << endl;
volScalarField MAT
(
    IOobject
    (
        "MAT",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);


Info<< "Creating field variables for solution procedure\n" << endl;

volScalarField A_C
(
    IOobject
    (
        "A_C",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("A_C", dimensionSet(0,0,-1,0,0,0,0), 0.0)
);
    
volScalarField A_M
(
    IOobject
    (
        "A_M",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("A_M", dimensionSet(0,0,-1,0,0,0,0), 0.0)
);
    
volScalarField phi_f
(
    IOobject
    (
        "phi_f",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("phi_f", dimensionSet(0,0,0,0,0,0,0), 0.0)
);    
    
volScalarField tau
(
    IOobject
    (
        "tau",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("tau", dimensionSet(1,-1,-2,0,0,0,0), 0.0)
);
    
volScalarField P_TSP
(
    IOobject
    (
        "P_TSP",
	runTime.timeName(),
	mesh,
	IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("P_TSP", dimensionSet(0,0,0,0,0,0,0), 0.0)
);

volScalarField beta_eps
(
    IOobject
    (
        "beta_eps",
	runTime.timeName(),
	mesh,
	IOobject::NO_READ,
	IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("beta_eps", dimensionSet(0,0,-1,0,0,0,0), 0.0)
);

volScalarField WSS
(
    IOobject
    (
        "WSS",
	runTime.timeName(),
	mesh,
	IOobject::NO_READ,
	IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("WSS", dimensionSet(1,-1,-2,0,0,0,0), 0.0)
);

volScalarField check
(
    IOobject
    (
        "check",
	runTime.timeName(),
	mesh,
	IOobject::NO_READ,
	IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("check", dimensionSet(0,0,0,0,0,0,0), 0.0)
);

Info<< "Reading transportProperties\n" << endl;
IOdictionary transportProperties
(
    IOobject
    (
        "transportProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);

dimensionedScalar nu
(
    "nu",
    dimViscosity,
    transportProperties.lookup("nu")
);

dimensionedScalar D_AP
(
    "D_AP",
    transportProperties.lookup("D_AP")
);

dimensionedScalar D_RP
(
    "D_RP",
    transportProperties.lookup("D_RP")
);

dimensionedScalar D_APR
(
    "D_APR",
    transportProperties.lookup("D_APR")
);

dimensionedScalar D_APS
(
    "D_APS",
    transportProperties.lookup("D_APS")
);

dimensionedScalar D_PT
(
    "D_PT",
    transportProperties.lookup("D_PT")
);

dimensionedScalar D_TRB
(
    "D_TRB",
    transportProperties.lookup("D_TRB")
);

dimensionedScalar D_ATIII
(
    "D_ATIII",
    transportProperties.lookup("D_ATIII")
);

dimensionedScalar H
(
    "H",
    transportProperties.lookup("H")
);

dimensionedScalar KRS
(
    "KRS",
    transportProperties.lookup("KRS")
);

dimensionedScalar KAS
(
    "KAS",
    transportProperties.lookup("KAS")
);

dimensionedScalar KAA
(
    "KAA",
    transportProperties.lookup("KAA")
);

dimensionedScalar TACT
(
    "TACT",
    transportProperties.lookup("TACT")
);

dimensionedScalar theta
(
    "theta",
    transportProperties.lookup("theta")
);

dimensionedScalar alpha
(
    "alpha",
    transportProperties.lookup("alpha")
);

dimensionedScalar beta
(
    "beta",
    transportProperties.lookup("beta")
);

dimensionedScalar K1_T
(
    "K1_T",
    transportProperties.lookup("K1_T")
);

dimensionedScalar KAT
(
    "KAT",
    transportProperties.lookup("KAT")
);

dimensionedScalar KT
(
    "KT",
    transportProperties.lookup("KT")
);

dimensionedScalar 
(
    "beta",
    transportProperties.lookup("beta")
);

dimensionedScalar phi_at
(
    "phi_at",
    transportProperties.lookup("phi_at")
);

dimensionedScalar phi_rt
(
    "phi_rt",
    transportProperties.lookup("phi_rt")
);

dimensionedScalar k1_j
(
    "k1_j",
    transportProperties.lookup("k1_j")
);

dimensionedScalar lambda_j
(
    "lambda_j",
    transportProperties.lookup("lambda_j")
);

dimensionedScalar spj
(
    "spj",
    transportProperties.lookup("spj")
);


dimensionedScalar tau_low_wall
(
    "tau_low_wall",
    transportProperties.lookup("tau_low_wall")
);

dimensionedScalar tau_high_wall
(
    "tau_high_wall",
    transportProperties.lookup("tau_high_wall")
);

dimensionedScalar tau_bd_wall
(
    "tau_bd_wall",
    transportProperties.lookup("tau_bd_wall")
);

dimensionedScalar tau_low_thr
(
    "tau_low_thr",
    transportProperties.lookup("tau_low_thr")
);

dimensionedScalar tau_high_thr
(
    "tau_high_thr",
    transportProperties.lookup("tau_high_thr")
);

dimensionedScalar tau_bd_thr
(
    "tau_bd_thr",
    transportProperties.lookup("tau_bd_thr")
);

dimensionedScalar rho
(
    "rho",
    transportProperties.lookup("rho")
);

dimensionedScalar eps_t
(
     "eps_t",
     transportProperties.lookup("eps_t")
);


dimensionedScalar shearThreshold
(
     "shearThreshold",
     transportProperties.lookup("shearThreshold")
);


#include "createPhi.H"


label pRefCell = 0;
scalar pRefValue = 0.0;
setRefCell(p, mesh.solutionDict().subDict("PISO"), pRefCell, pRefValue);
mesh.setFluxRequired(p.name());

singlePhaseTransportModel laminarTransport(U, phi);

autoPtr<incompressible::momentumTransportModel> turbulence
(
    incompressible::momentumTransportModel::New(U, phi, laminarTransport)
);

#include "createMRF.H"
#include "createFvOptions.H"
