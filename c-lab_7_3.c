#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int **inputArray(int n) {
    int max = 100, min = -100;
    srand(time(NULL));
    if (n <= 0) {
        printf("Error");
        exit(1);
    }
    int **array = (int **) malloc(n * sizeof(int));
    for (int j = 0; j < n; ++j) {
        array[j] = (int *) malloc(n * sizeof(int));
    }
    if (!array) {
        printf("Error");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j < n; ++j) {
            array[i][j] = min + rand() % (max - min + 1);
            printf("%d ", array[i][j]);
        }
    }
    return array;
}

int validateMatrix(int **array, int n) {
    int bool = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i][j] != array[n - 1 - j][n - 1 - i]) {
                bool = 0;
                break;
            }
        }
    }
    return bool;
}

int main() {
    printf("Enter n - ");
    int n = 0;
    scanf("%d", &n);
    int **array = inputArray(n);
    if (validateMatrix(array, n) == 1) {
        printf("Square matrix symmetric with respect to the side diagonal.");
    } else {
        printf("The square matrix is not symmetrical with respect to the side diagonal.");
    }
    return 0;
}
