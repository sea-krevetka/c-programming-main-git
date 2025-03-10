// quick sort

#include <stdio.h>

int median(int arr[], int n) {
    int maxel = arr[0];
    int minel = arr[0];

    for (int i=1; i<n; i++) {
        if (arr[i]>maxel) {
            maxel = arr[i];
        }
        if (arr[i] < minel) {
            minel = arr[i];
        }
    }
    
    return (maxel + minel)/2;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high, int pivot) {
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int n = high - low + 1;
        int med = median(arr + low, n);
        
        int pivotIndex = partition(arr, low, high, med);

        QuickSort(arr, low, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    QuickSort(arr, 0, n - 1);
    
    printf("Отсортированный массив: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}