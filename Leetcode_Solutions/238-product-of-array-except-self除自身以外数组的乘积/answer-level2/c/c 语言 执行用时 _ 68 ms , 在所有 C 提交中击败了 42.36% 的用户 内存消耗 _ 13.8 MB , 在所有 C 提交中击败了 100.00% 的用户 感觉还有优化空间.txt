### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int left[100000] = {1};
    int right[100000] = {1};
    *returnSize = numsSize;
    left[0] = 1;
    right[numsSize - 1] = 1;
    for (int i = 1; i < numsSize; i++) {
        left[i] = left[i - 1] * nums[i - 1];
        right[numsSize - 1 - i] = right[numsSize - i] * nums[numsSize - i];
    }

    int *result = (int *)malloc(sizeof(int) * (numsSize + 1));
    for (int j = 0; j < numsSize; j++) {
        result[j] = left[j] * right[j];
    }
    return result;
}
```