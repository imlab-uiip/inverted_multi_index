//
// Created by dima on 05.04.17.
//

#ifndef CBLASWRAPS_H
#define CBLASWRAPS_H

#include "cblas.h"

static inline void saxpy(const float alpha, const float *x, const int len, float *y) {
    cblas_saxpy(len, alpha, x, 1, y, 1);
}

static inline float dot_product(const float *x, const float *y, const int len) {
    float p = cblas_sdot(len, x, 1, y, 1);
    return p;
}

static inline float sqr_euclidean_norm(const float *x, const int len) {
    float n = cblas_sdot(len, x, 1, x, 1);
    return n;
}

static inline void sqr_euclidean_norms(const float *a, const size_t rows, const size_t columns, float *out_sqr_norms) {
    for (size_t i = 0; i < rows; i++) {
        float sqr_norm = sqr_euclidean_norm(&a[i * columns], columns);
        out_sqr_norms[i] = sqr_norm;
    }
}

static inline void
sgemv(const float alpha, const float *a, const int rows, const int columns, const int beta, const float *x,
      float *y) {
    cblas_sgemv(CBLAS_ORDER::CblasRowMajor, CBLAS_TRANSPOSE::CblasNoTrans, rows, columns, alpha, a, columns,
                x, 1, beta, y, 1);
}

#endif //EUCLIDEANDISTANCECOMPUTER_CBLAS_WRAPS_H