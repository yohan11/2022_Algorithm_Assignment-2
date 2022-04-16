#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* testCase(int num){
	int random; 
    int* randArray;
    randArray = (int *)malloc(sizeof(int));
    srand(time(NULL));

	for (int i = 0; i < num; i++) { 
        random = rand()%num;
		randArray[i]=random;
}
    return randArray;
}

void exchangeSort(int *arr, int size){
    int i, j, temp;

    for(i=0;i<size;++i){
		for(j=i+1;j<size+1;j++){
			if(arr[i]>arr[j]){
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}

	for(i=0;i<size;i++){
		printf("%d ", arr[i]);
	}
}

int main(){
    int size=10000;
	exchangeSort(testCase(size),size);
	return 0;
}

