#ifndef GSL_MATRIX_LONG_DOUBLE_EXTRA_H
#define GSL_MATRIX_LONG_DOUBLE_EXTRA_H

typedef long double ldouble_t;

#include <gsl/gsl_matrix_long_double.h>

ldouble_t gsl_matrix_long_double_column_max_by(gsl_matrix_long_double *, size_t, size_t *, ldouble_t(*_Nonnull)(ldouble_t));

#endif // GSL_MATRIX_LONG_DOUBLE_EXTRA_H