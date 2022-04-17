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

void heapify(int *arr, int size){
    for(int i=1;i<size;++i){
        int child = i;
        do{
            int root = (child-1)/2;
            if(arr[root]<arr[child]){
                int temp = arr[root];
                arr[root] = arr[child];
                arr[child] = temp;
            }
            child = root;
        }while(child!=0);   
    }
}

void heap(int *arr, int *size){
    int temp = arr[0];
    arr[0] = arr[*size-1];
    arr[*size-1] = temp;
    --(*size);
}

int main(){    
    int size = 10000;
    int data_size=10000;

    int* data=testCase(size);
    
    for(int i=0;i<data_size;++i){
        heapify(data, size);
        heap(data, &size);
    }
    
    for(int i=0;i<data_size;++i){
        printf("%d ", data[i]);
    }
    
    return 0;
}