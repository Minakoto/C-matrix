#include "s21_matrix.h"



START_TEST(sum_test_1) {
    matrix_t mt1, mt2, res;
    s21_create_matrix(2, 2, &mt1);
    s21_create_matrix(2, 2, &mt2);
    mt1.matrix[0][0] = 1.0;
    mt1.matrix[0][1] = 2.0;
    mt1.matrix[1][0] = 3.0;
    mt1.matrix[1][1] = 4.0;
    mt2.matrix[0][0] = 1.0;
    mt2.matrix[0][1] = 2.0;
    mt2.matrix[1][0] = 3.0;
    mt2.matrix[1][1] = 4.0;
    
    s21_sum_matrix(&mt1, &mt2, &res);
    
    s21_remove_matrix(&mt1);
    s21_remove_matrix(&mt2);
    s21_remove_matrix(&res);
}

