#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Dynamic memory allocation for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed. Exiting...");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find maximum and minimum
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min); // Corrected line

    // Free the allocated memory
    free(arr);

    return 0;
}
