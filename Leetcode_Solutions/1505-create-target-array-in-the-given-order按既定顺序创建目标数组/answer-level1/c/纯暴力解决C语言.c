每次在插入的位置 先向右移位, 在赋值

```


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    *returnSize = numsSize;
    if (numsSize == 0) {
        return NULL;
    }
    int* ret = (int*)calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        int temp = index[i];
        for (int j = indexSize - 2; j >= temp; j--) {
            ret[j + 1] = ret[j];
        } 
        ret[temp] = nums[i];
    }
    
    return ret;
}

```
