#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int res = SUCCESS;
    if(!A->matrix || !B->matrix) res = FAILURE;
    if(res == SUCCESS && !s21_compare_sizes(A, B)) res = FAILURE;
    for(int r = 0; res == SUCCESS && r < A->rows; r++) {
        for(int c = 0; res == SUCCESS && c < A->columns; c++) 
            if(A->matrix[r][c] != B->matrix[r][c]) res = FAILURE;
    }
    return res;
}
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int res = OP_SUCCESS;
    int row, col;
    if(!A->matrix || !B->matrix) res = OP_MATRIX_ERROR;
    if(!s21_compare_sizes(A, B)) res = OP_MATRIX_ERROR;
    if(res == OP_SUCCESS) {
        row = A->rows;
        col = A->columns;
        if(!result->matrix) res = s21_create_matrix(row, col, result);
        for(int r = 0; res == OP_SUCCESS && r < row; r++) {
            for(int c = 0; c < col; c++)
                result->matrix[r][c] = A->matrix[r][c] + B->matrix[r][c];   
        }
    }
    return res;
}
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int res = OP_SUCCESS;
    int row, col;
    if(!A->matrix || !B->matrix) res = OP_MATRIX_ERROR;
    if(!s21_compare_sizes(A, B)) res = OP_MATRIX_ERROR;
    if(res == OP_SUCCESS) {
        row = A->rows;
        col = A->columns;
        if(!result->matrix) res = s21_create_matrix(row, col, result);
        for(int r = 0; res == OP_SUCCESS && r < row; r++) {
            for(int c = 0; c < col; c++)
                result->matrix[r][c] = A->matrix[r][c] - B->matrix[r][c];   
        }
    }
    return res;
}
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    int res = OP_SUCCESS;
    int row, col;
    if(!A->matrix) res = OP_MATRIX_ERROR;
    if(res == OP_SUCCESS) {
        row = A->rows;
        col = A->columns;
        if(!result->matrix) res = s21_create_matrix(row, col, result);
        for(int r = 0; res == OP_SUCCESS && r < row; r++) {
            for(int c = 0; c < col; c++)
                result->matrix[r][c] = number * A->matrix[r][c];   
        }
    }
    return res;
}
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int res = OP_SUCCESS;
    int row, col;
    if(!A->matrix || !B->matrix) res = OP_MATRIX_ERROR;
    if(!s21_compare_sizes_mul(A, B)) res = OP_MATRIX_ERROR;
    if(res == OP_SUCCESS) {
        row = A->rows;
        col = B->columns;
        if(result->matrix) s21_remove_matrix(result);
        res = s21_create_matrix(row, col, result);
        for(int r = 0; r < row; r++) {
            for(int c = 0; c < col; c++) result->matrix[r][c] = s21_mult_part(r, c, A, B);
        }
    }
    return res;
}