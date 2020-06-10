#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int maximalAbsElementOfTheArray(int *array, int n) {
    int max = 0;
    for (int i = 0; i < n; ++i) {
        if (abs(max) < abs(array[i])) {
            max = array[i];
        }
    }
    return max;
}

int sum(const int *array, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (array[i] == 0){
            for (int j = i+1; j < n; ++j) {
                sum += + array[j];
            }
        }
    }
    return sum;
}
int * inputArray(int n){
    int max = 100, min = -100;
    srand(time(NULL));
    if (n <= 0){
        printf("Error");
        exit(1);
    }
    int *array = (int*)malloc(n*sizeof(int));
    if (!array){
        printf("Error");
        exit(1);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        array[i] = min + rand() % (max-min+1);
        printf("%d ",array[i]);
    }
    return array;
}

int main() {
    printf("Enter n - ");
    int n = 0;
    scanf("%d", &n);
    int * array = inputArray(n);
    printf("Maximal abs element of the array - %d", maximalAbsElementOfTheArray(array, n));
    printf("\nAmount between the first and second negative element of the matrix - %d", sum(array, n));
    return 0;
}
