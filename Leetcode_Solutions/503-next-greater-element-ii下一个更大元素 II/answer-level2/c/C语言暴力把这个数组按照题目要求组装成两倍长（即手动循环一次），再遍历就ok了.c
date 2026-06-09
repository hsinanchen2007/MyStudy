```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int* new_nums = (int*)malloc(sizeof(int) * numsSize * 2);
    int* res = (int*)malloc(sizeof(int) * numsSize);
    int i, j;
    for(i = 0; i < numsSize; i++) {
        new_nums[i] = nums[i];
        new_nums[i + numsSize] = nums[i];
    }

    for(i = 0; i < numsSize; i++) {
        for(j = i + 1; j < (numsSize * 2); j++) {
            if(new_nums[j] > new_nums[i]) {
                res[i] = new_nums[j];
                break;
            }
        }
        if(j == (numsSize * 2)) {
            res[i] = -1;
        }
    }
    return res;
}
```

