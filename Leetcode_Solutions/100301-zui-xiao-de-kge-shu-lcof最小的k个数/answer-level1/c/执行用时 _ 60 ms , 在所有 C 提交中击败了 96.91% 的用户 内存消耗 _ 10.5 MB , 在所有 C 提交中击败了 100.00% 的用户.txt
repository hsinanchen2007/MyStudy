### 解题思路
用了假quicksort

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int *ans=(int*)malloc(sizeof(int)*k);
    quicksort(arr, arrSize);
    for(int i=0; i<k; i++) ans[i]=arr[i];
    *returnSize=k;
    return ans;
}
 void quicksort(int a[],int n){
	int i=0, j=n-1, pivot = a[0]; 
	while(i < j){
		while(i < j && a[j] > pivot) j--; 
		if(i < j) a[i++] = a[j]; 
		while(i < j && a[i] <= pivot) i++; 
		if(i < j) a[j--] = a[i];
	} 
	a[i] = pivot; 
		if(i > 1) quicksort(a,i); 
		if(n-i-1 > 1) quicksort(a+i+1,n-i-1);
} 
```