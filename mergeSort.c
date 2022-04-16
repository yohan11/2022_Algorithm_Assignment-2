# include <stdio.h>
#include <stdlib.h>
#include <time.h>
# define MAX_SIZE 100
int sorted[MAX_SIZE]; 

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

void merge(int* arr, int left, int mid, int right){
  int i, j, k, l;
  i = left;
  j = mid+1;
  k = left;

  while(i<=mid && j<=right){
    if(arr[i]<=arr[j])
      sorted[k++] = arr[i++];
    else
      sorted[k++] = arr[j++];
  }

  if(i>mid){
    for(l=j; l<=right; l++)
      sorted[k++] = arr[l];
  }

  else{
    for(l=i; l<=mid; l++)
      sorted[k++] = arr[l];
  }

  for(l=left; l<=right; l++){
    arr[l] = sorted[l];
  }
}

void merge_sort(int* arr, int left, int right){
  int mid;

  if(left<right){
    mid = (left+right)/2; 
    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right); 
    merge(arr, left, mid, right); 
  }
}

int main(){
  int size = MAX_SIZE;

  merge_sort(testCase(size), 0, size-1);

  for(int i=0; i<size; i++){
    printf("%d ", sorted[i]);
  }
}
