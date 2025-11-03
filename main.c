/* Версия из master ветки */чC
// Поддержка Linux
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ARRAY_SIZE 23
#define MATRIX_ROWS 7
#define MATRIX_COLS 5

typedef int (*find_array_func)(int arr[], int size);
typedef int (*find_matrix_func)(int matrix[][5], int rows, int cols);

void fill_array_random(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 101 - 50;
    }
}

void fill_matrix_random(int matrix[][MATRIX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 101 - 50;
        }
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%4d", arr[i]);
    }
    printf("\n");
}

void print_matrix(int matrix[][MATRIX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

void use_array_library() {
    HINSTANCE hArrayLib = LoadLibrary("libarray.dll");
    if (!hArrayLib) {
        printf("Oshibka zagruzki biblioteku massivov\n");
        return;
    }

    find_array_func find_largest_negative = (find_array_func)GetProcAddress(hArrayLib, "find_largest_negative_array");
    if (!find_largest_negative) {
        printf("Oshibka v biblioteke massivov\n");
        FreeLibrary(hArrayLib);
        return;
    }

    int array[ARRAY_SIZE];
    fill_array_random(array, ARRAY_SIZE);

    printf("Massiv (%d elementov):\n", ARRAY_SIZE);
    print_array(array, ARRAY_SIZE);

    int result = find_largest_negative(array, ARRAY_SIZE);

    if (result != 0) {
        printf("Naibolshiy otricatelniy element v massive: %d\n", result);
    }
    else {
        printf("Net otricatelnyh chisel v massive\n");
    }

    FreeLibrary(hArrayLib);
}

void use_matrix_library() {
    HINSTANCE hMatrixLib = LoadLibrary("libmatrix.dll");
    if (!hMatrixLib) {
        printf("Oshibka zagruzki biblioteku matric\n");
        return;
    }

    find_matrix_func find_largest_negative = (find_matrix_func)GetProcAddress(hMatrixLib, "find_largest_negative_matrix");
    if (!find_largest_negative) {
        printf("Oshibka v biblioteke matric\n");
        FreeLibrary(hMatrixLib);
        return;
    }

    int matrix[MATRIX_ROWS][MATRIX_COLS];
    fill_matrix_random(matrix, MATRIX_ROWS, MATRIX_COLS);

    printf("Matrica (%dx%d):\n", MATRIX_ROWS, MATRIX_COLS);
    print_matrix(matrix, MATRIX_ROWS, MATRIX_COLS);

    int result = find_largest_negative(matrix, MATRIX_ROWS, MATRIX_COLS);

    if (result != 0) {
        printf("Naibolshiy otricatelniy element v matrice: %d\n", result);
    }
    else {
        printf("Net otricatelnyh chisel v matrice\n");
    }

    FreeLibrary(hMatrixLib);
}

int main() {
    srand(time(NULL));
    int choice;

    do {
        printf("\n menu \n");
        printf("1 - Rabota s massivom\n");
        printf("2 - Rabota s matricey\n");
        printf("0 - exit\n");
        printf("Vash vybor: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\n Rabota s massivom \n");
            use_array_library();
            break;
        case 2:
            printf("\n Rabota s matricey \n");
            use_matrix_library();
            break;
        case 0:
            break;
        default:
            printf("Nevernyy vybor\n");
        }

    } while (choice != 0);

    return 0;
}
// Поддержка Linux
