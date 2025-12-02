#include <stdio.h>

int* larger(int *a, int *b) {
    if (*a > *b) {
        return a;
    }
    return b;
}

int main(void) {
    int x, y;

    printf("Enter two integers: ");
    if (scanf("%d %d", &x, &y) != 2) {
        puts("Invalid input.");
        return 1;
    }

    int *ptr = larger(&x, &y);

    printf("The larger value is: %d\n", *ptr);

    return 0;
}
