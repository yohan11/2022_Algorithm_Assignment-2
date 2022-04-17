#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* testCase(int num) {
    int random;
    int* randArray;
    randArray = (int*)malloc(sizeof(int) * num); 
    srand(time(NULL));

    for (int i = 0; i < num; i++) {

        random = rand() % num;
        randArray[i] = random;
    }
    return randArray;
}

void quickSort(int* arr, int start, int end) {
    int pivot = start; 
    int i = start + 1; 
    int j = end;
    int temp;

    if(start>=end){
        return;
    } 

    while (i <= j) {
        while (i <= end && arr[i] <= arr[pivot]) {
            i++; 
        }
        while (j > start && arr[j] >= arr[pivot]) {
            j--; 
        }
        if (i > j) {
            temp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = temp; 
        } else {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp; 
        }
    }
    quickSort(arr, start, j - 1); 
    quickSort(arr, j + 1, end); 
}

int main(void) {
    int size=10;
    int* data = testCase(size); 

    quickSort(data, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }

    return 0;
}
