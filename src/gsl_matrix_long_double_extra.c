#include "gsl/gsl_matrix_long_double_extra.h"

ldouble_t gsl_matrix_long_double_column_max_by(gsl_matrix_long_double *s, size_t col, size_t *row_m,
                                               ldouble_t (*_Nonnull func)(ldouble_t))
{
    if (col >= s->size2)
        GSL_ERROR("col >= num of columns, in gsl_matrix_long_double_column_max_by", GSL_EBADLEN);

    ldouble_t max = matrix_get(s, 0, col);
    ldouble_t func_max = func(max);
    size_t i_m = 0;

    for (size_t i = 0; i < s->size1; i++)
    {
        ldouble_t tmp = matrix_get(s, i, col);
        ldouble_t func_tmp = func(tmp);

        if (func_tmp > func_max)
            i_m = i, max = tmp, func_max = func_tmp;
    }

    *row_m = i_m;
    return max;
}