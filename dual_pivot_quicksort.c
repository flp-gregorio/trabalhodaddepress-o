#include <stdio.h>

void dual_pivot_quicksort(int arr[], int left, int right) {
    if (right <= left) {
        return;
    }

    // escolhendo os dois pivôs aleatórios
    if (arr[left] > arr[right]) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }
    int p = arr[left];
    int q = arr[right];

    // particionando a lista com base nos pivôs
    int l = left + 1;
    int g = right - 1;
    int k = l;
    while (k <= g) {
        if (arr[k] < p) {
            int temp = arr[k];
            arr[k] = arr[l];
            arr[l] = temp;
            l++;
        } else if (arr[k] >= q) {
            while (arr[g] > q && k < g) {
                g--;
            }
            int temp = arr[k];
            arr[k] = arr[g];
            arr[g] = temp;
            g--;
            if (arr[k] < p) {
                temp = arr[k];
                arr[k] = arr[l];
                arr[l] = temp;
                l++;
            }
        }
        k++;
    }

    // colocando os pivôs em suas posições finais
    l--;
    g++;
    int temp = arr[left];
    arr[left] = arr[l];
    arr[l] = temp;
    temp = arr[right];
    arr[right] = arr[g];
    arr[g] = temp;

    // chamando a função recursivamente para as sub-listas
    dual_pivot_quicksort(arr, left, l - 1);
    if (arr[l] < arr[g]) {
        dual_pivot_quicksort(arr, l + 1, g - 1);
    }
    dual_pivot_quicksort(arr, g + 1, right);
}