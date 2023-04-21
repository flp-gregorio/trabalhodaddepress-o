#include <stdio.h>
#include "dual_pivot_quicksort.h"

int main() {
    int a[] = {1, 234, 345, 342, 5634, 523, 52, 564, 6, 345, 2, 345, 235};
    int n = sizeof(a) / sizeof(a[0]);

    dual_pivot_quicksort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}