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

void quicksort(int* arr, int start, int end) {
    if (start >= end) {
        return;
    }
    int key = start;
    int i = start + 1;
    int j = end;
    int temp;

    while (i <= j) {
        while (i <= end && arr[i] <= arr[key]) {
            i++;
        }
        while (j > start && arr[j] >= arr[key]) {
            j--;
        }
        if (i > j) {
            temp = arr[j];
            arr[j] = arr[key];
            arr[key] = temp;
        } else {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    quicksort(arr, start, j - 1);
    quicksort(arr, j + 1, end);

}

int main(void) {
    int size=10;
    int* data = testCase(size); 

    quicksort(data, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }

    return 0;
}