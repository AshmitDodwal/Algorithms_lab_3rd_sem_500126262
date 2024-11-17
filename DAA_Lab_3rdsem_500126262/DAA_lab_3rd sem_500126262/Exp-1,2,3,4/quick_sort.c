#include <stdio.h>
void quickSort(int arr[], int l, int h) {
    if (l < h) {
        int pivot = arr[h];
        int i = l;
        for (int j = l; j < h; j++) {
            if (arr[j] < pivot) { 
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
            }
        }
        int temp = arr[i];
        arr[i] = arr[h];
        arr[h] = temp;
        quickSort(arr, l, i - 1);
        quickSort(arr, i + 1, h);
    }
}
int main() {
    int n;
    printf("Enter length of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of array: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
