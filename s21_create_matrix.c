#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    int res = OP_SUCCESS;
    matrix_t new_matrix = {NULL, rows, columns};
    if(rows <= 0 || columns <= 0) res = OP_MATRIX_ERROR;
    if(res == OP_SUCCESS) {
        new_matrix.matrix = (double**) malloc(new_matrix.rows * sizeof(double*));
        if(!new_matrix.matrix) res = OP_MATRIX_ERROR;
        for(int i = 0; res == OP_SUCCESS && i < new_matrix.rows; i++) {
            new_matrix.matrix[i] = (double*) malloc(new_matrix.columns * sizeof(double));
            if(!new_matrix.matrix[i]) {
                res = OP_MATRIX_ERROR;
                free(new_matrix.matrix);
            }
        }
        if(res == OP_SUCCESS && result) *result = new_matrix;
        else {} // mb destroy
    }
    return res;
}