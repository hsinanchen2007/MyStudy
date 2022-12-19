### 解题思路
1. C语言qsort解决

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int CmpFunc(int *a, int *b)
{
    return *a - *b;
}

int* sortArray(int* nums, int numsSize, int* returnSize)
{
    if (nums == NULL || numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int* newNums = (int *)malloc(numsSize * sizeof(int));
    if (newNums != NULL) {
        memset(newNums, 0, numsSize * sizeof(int));
    }

    for (int i = 0; i < numsSize; i++) {
        newNums[i] = nums[i];
    }

    qsort(newNums, numsSize, sizeof(newNums[0]), CmpFunc);
    *returnSize = numsSize;
    return newNums;
}
```