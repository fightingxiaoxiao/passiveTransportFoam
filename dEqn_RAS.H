
    Info << "use turbulent diffusion term." << endl;

    fvScalarMatrix dEqn
    (
      fvm::ddt(driftDensity)
      + fvm::div(phi, driftDensity)                 // 被动输运         // passive transport
      + fvm::div(phiWf, driftDensity)             // 以速度wf下落    // fall down with velocity w_f
      - fvm::laplacian(turbulence->nut()/S_ct, driftDensity)   // 湍流扩散         // turbulent diffusion
      ==
        fvOptions(driftDensity)
    );

    dEqn.relax();

    fvOptions.constrain(dEqn);

    dEqn.solve();
    
    fvOptions.correct(driftDensity);