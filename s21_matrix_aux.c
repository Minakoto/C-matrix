#include "s21_matrix.h"

int s21_compare_sizes(matrix_t* A, matrix_t* B) {
    return (A->rows == B->rows) && (A->columns == B->columns);
}

int s21_compare_sizes_mul(matrix_t* A, matrix_t* B) {
    return (A->columns == B->rows);
}