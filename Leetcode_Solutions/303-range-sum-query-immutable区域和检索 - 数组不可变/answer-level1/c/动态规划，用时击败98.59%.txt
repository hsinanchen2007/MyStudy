### 解题思路
动态规划，用数组保存和
(obj->sums[j] - obj->sums[i] + obj->nums[i]);

### 代码

```c
typedef struct {
    int *nums;
    int *sums;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    if(numsSize == 0)
        return NULL;
    NumArray *myArray = (NumArray *)malloc(sizeof(NumArray));
    int i = 1;
    myArray->nums = nums;
    myArray->sums = (int *)malloc(numsSize * sizeof(int));
    myArray->sums[0] = nums[0];
    for(; i < numsSize; i++){
        myArray->sums[i] = myArray->sums[i-1] + nums[i];
    }
    return myArray;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    //if(obj != NULL)
    return(obj->sums[j] - obj->sums[i] + obj->nums[i]);
    //return 0;
}

void numArrayFree(NumArray* obj) {
    if(obj != NULL){
        free(obj->sums);
        free(obj);
    }

}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/
```