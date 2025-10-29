// ====================================================
// Derivatives for psi
// ====================================================
#if defined(USE_FIRST_DERIV_TWICE)
#  pragma message("HK-47: Compiled WITH USE_FIRST_DERIV_TWICE")
#else
#  pragma message("HK-47: Compiled WITHOUT USE_FIRST_DERIV_TWICE")
#endif

// Always compute 1st derivs for psi
dendro_derivs::deriv_x(grad_0_psi, psi, hx, sz, bflag);
dendro_derivs::deriv_y(grad_1_psi, psi, hy, sz, bflag);
dendro_derivs::deriv_z(grad_2_psi, psi, hz, sz, bflag);

#ifdef USE_FIRST_DERIV_TWICE
  // Compute "2nd derivs" using first derivs
  dendro_derivs::deriv_x(grad2_0_0_psi, grad_0_psi, hx, sz, bflag);
  dendro_derivs::deriv_y(grad2_1_1_psi, grad_1_psi, hy, sz, bflag);
  dendro_derivs::deriv_z(grad2_2_2_psi, grad_2_psi, hz, sz, bflag);
#else
  // Normal 2nd derivs
  dendro_derivs::deriv_xx(grad2_0_0_psi, psi, hx, sz, bflag);
  dendro_derivs::deriv_yy(grad2_1_1_psi, psi, hy, sz, bflag);
  dendro_derivs::deriv_zz(grad2_2_2_psi, psi, hz, sz, bflag);
#endif


// ====================================================
// Derivatives for Gamma
// ====================================================

// Always compute 1st derivs for Gamma
dendro_derivs::deriv_x(grad_0_Gamma, Gamma, hx, sz, bflag);
dendro_derivs::deriv_y(grad_1_Gamma, Gamma, hy, sz, bflag);
dendro_derivs::deriv_z(grad_2_Gamma, Gamma, hz, sz, bflag);

// Gamma does not need 2nd derivs in your snippet


// ====================================================
// Derivatives for A0
// ====================================================

// Always compute 1st derivs for A0
dendro_derivs::deriv_x(grad_0_A0, A0, hx, sz, bflag);
dendro_derivs::deriv_y(grad_1_A0, A0, hy, sz, bflag);
dendro_derivs::deriv_z(grad_2_A0, A0, hz, sz, bflag);

#ifdef USE_FIRST_DERIV_TWICE
  dendro_derivs::deriv_x(grad2_0_0_A0, grad_0_A0, hx, sz, bflag);
  dendro_derivs::deriv_y(grad2_1_1_A0, grad_1_A0, hy, sz, bflag);
  dendro_derivs::deriv_z(grad2_2_2_A0, grad_2_A0, hz, sz, bflag);
#else
  dendro_derivs::deriv_xx(grad2_0_0_A0, A0, hx, sz, bflag);
  dendro_derivs::deriv_yy(grad2_1_1_A0, A0, hy, sz, bflag);
  dendro_derivs::deriv_zz(grad2_2_2_A0, A0, hz, sz, bflag);
#endif
