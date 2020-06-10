#include <stdio.h>
#include <math.h>

int minimalAbsElementOfTheArray(int *array, int n) {
    int min = 100;
    for (int i = 0; i < n; ++i) {
        if (abs(min) > abs(array[i])) {
            min = array[i];
        }
    }
    return min;
}

int sum(const int *array, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] < 0) {
            for (int j = i + 1; array[j] > 0; j++) {
                sum += array[j];
            }
            return sum;
        }
    }
    return sum;
}

int main() {
    int array[5] = {3, -7, 12, -13, -7};
    printf("Minimal abs element of the array - %d", minimalAbsElementOfTheArray(array, 5));
    printf("\nAmount between the first and second negative element of the matrix - %d", sum(array, 5));
    return 0;
}
