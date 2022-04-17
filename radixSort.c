#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* testCase(int num){
    int random; 
    int* randArray;
    randArray = (int *)malloc(sizeof(int)*num);
    srand(time(NULL));

    for (int i = 0; i < num; i++) {         
        random = rand()%num;
        randArray[i]=random;
}
    return randArray;
}

int getMax(int* arr, int size) {
  int max = arr[0];
  for (int i = 1; i < size; i++)
    if (arr[i] > max)
      max = arr[i];
  return max;
}

void countSort(int* arr, int n, int exp) {
	int buffer[n];
    int i, count[10] = {0};
    
    for (i = 0; i < n; i++){
        count[(arr[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        buffer[count[(arr[i]/exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++){
        arr[i] = buffer[i];
    }
}

void radixSort(int* arr, int n) {
    int m = getMax(arr, n);
    
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

int main() {
    int size=10000;
    int* data=testCase(size);
    radixSort(data, size);
    
    for (int i = 0; i < size; i++){
        printf("%d ",data[i]);
    }
    return 0;
}