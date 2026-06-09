### 解题思路
记录用

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int Paratition(int* A,int low,int high){
    int pivot=A[low];
    while(low<high){
        while(low<high && A[high]>=pivot) --high;
        A[low]=A[high];
        while(low<high && A[low]<=pivot) ++low;
        A[high]=A[low];
    }
    A[low]=pivot;
    return low;
}
void Quicksort(int* A,int low,int high){
    if(low<high){
        int pivotpos=Paratition(A,low,high);
        Quicksort(A,low,pivotpos-1);
        Quicksort(A,pivotpos+1,high);
    }
}
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize=numsSize;
    Quicksort(nums,0,numsSize-1);
    return nums;
}
```
