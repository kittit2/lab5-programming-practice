#include "matrix_utils.h"
#include <limits.h>

int find_largest_negative_matrix(int matrix[][5], int rows, int cols) {
    int largest_negative = INT_MIN;
    int found = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < 0 && matrix[i][j] > largest_negative) {
                largest_negative = matrix[i][j];
                found = 1;
            }
        }
    }
    return found ? largest_negative : 0;
}