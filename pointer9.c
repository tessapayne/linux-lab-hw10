#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    printf("How many elements? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        puts("Invalid n.");
        return 1;
    }

    int *a = malloc((size_t)n * sizeof *a);
    if (!a) {
        puts("Allocation failed.");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            puts("Invalid input.");
            free(a);
            return 1;
        }
    }

    int *maxp = a;
    for (int i = 1; i < n; i++) {
        int *p = a + i;
        if (*p > *maxp) maxp = p;
    }

    printf("Largest = %d (at index %ld)\n", *maxp, (long)(maxp - a));

    free(a);
    return 0;
}
