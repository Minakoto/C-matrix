#include "s21_matrix.h"

int s21_compare_sizes(matrix_t* A, matrix_t* B) {
    return (A->rows == B->rows) && (A->columns == B->columns);
}

int s21_compare_sizes_mul(matrix_t* A, matrix_t* B) {
    return (A->columns == B->rows);
}

double s21_mult_part(int r, int c, matrix_t* A, matrix_t* B) {
    double res = 0;
    for(int j = 0; j < A->columns; j++) {
        res += A->matrix[r][j] * B->matrix[j][c];
    }
    return res;
}