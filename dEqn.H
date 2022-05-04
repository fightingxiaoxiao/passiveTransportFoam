    fvScalarMatrix dEqn
    (
      fvm::ddt(driftDensity)
      + fvm::div(phi, driftDensity)                 // 被运         // passive transport
      + fvm::div(phiWf, driftDensity)             // 以速度w下落    // fall down with velocity w_f
      - fvm::laplacian(turbulence->nut()/S_ct, driftDensity)   // 湍散         // turbulent diffusion
      ==
        fvOptions(driftDensity)
    );

    dEqn.relax();
    fvOptions.constrain(dEqn);
    fvOptions.correct(driftDensity);
    