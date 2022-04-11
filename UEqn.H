    fvVectorMatrix UEqn
    (
        fvm::ddt(rho, U)
      + fvm::div(rhoPhi, U)
      //+ turbulence->divDevRhoReff(rho, U)
      - mixture.divTauMF(U)//eklendi "+" veya "-" dikkat et
      
    );

    UEqn.relax();
/*
    if (pimple.momentumPredictor())
    {
        solve(UEqn == -fvc::grad(p));
    }
*/
//    spSolverU->solve(UEqn == -fvc::grad(p));  //constit. eklendi

    if (pimple.momentumPredictor())
    {
        solve(UEqn == -fvc::grad(p));
    }
    
    Info<< "max(U) " << max(mag(U)).value() << endl;
