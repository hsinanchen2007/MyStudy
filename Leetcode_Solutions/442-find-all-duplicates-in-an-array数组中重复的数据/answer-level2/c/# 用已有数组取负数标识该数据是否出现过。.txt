# 用已有数组取负数标识该数据是否出现过。
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize){
    *returnSize = 0;
    if (nums == NULL || numsSize < 2) {
        return NULL;
    }
    int *ret = (int *)malloc(numsSize / 2 * sizeof(int));
    memset(ret, 0, numsSize / 2 * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        int absNum = abs(nums[i]);
        if (absNum > numsSize) {
            continue;
        }
        if (nums[absNum - 1] < 0) {
            ret[*returnSize] = absNum;
            *returnSize = *returnSize + 1;
        }else {
            nums[absNum - 1] = -nums[absNum - 1];
        }
    }
    return ret;
}
```
