### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int* nums, int numsSize, int* returnSize){
    if (nums == NULL || numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int i, k;
    int j = 0;
    *returnSize = 0;
    for (i = 0; i < numsSize; i += 2) {
        *returnSize += nums[i];
    }

    int *result = (int *)malloc(sizeof(int) * (*returnSize));
    for (i = 0; i < numsSize - 1; i += 2) {
        for (k = 0; k < nums[i]; k++) {
            result[j++] = nums[i + 1];
        }
    }

    return result;
}
```