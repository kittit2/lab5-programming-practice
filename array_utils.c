#include "array_utils.h"
#include <limits.h>

int find_largest_negative_array(int arr[], int size) {
    int largest_negative = INT_MIN;
    int found = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0 && arr[i] > largest_negative) {
            largest_negative = arr[i];
            found = 1;
        }
    }
    return found ? largest_negative : 0;
}