//
// Created by milinda on 1/16/19.
//

#include "dataUtils.h"

namespace dsolve {


bool isReMeshWAMR(
    ot::Mesh *pMesh, const double **unzippedVec, const unsigned int *varIds,
    const unsigned int numVars,
    std::function<double(double, double, double, double *)> wavelet_tol,
    double amr_coarse_fac) {
    return pMesh->isReMeshUnzip(
        unzippedVec, varIds, numVars, wavelet_tol, amr_coarse_fac,
        DENDRO_REMESH_UNZIP_SCALE_FAC, dsolve::SOLVER_DERIV_FIRST_WEIGHT,
        dsolve::SOLVER_DERIV_SECOND_WEIGHT);
}

// ignoring remesh bh radial, in BSSN code, but Milinda says it's too expensive
// to use

}  // end of namespace dsolve
