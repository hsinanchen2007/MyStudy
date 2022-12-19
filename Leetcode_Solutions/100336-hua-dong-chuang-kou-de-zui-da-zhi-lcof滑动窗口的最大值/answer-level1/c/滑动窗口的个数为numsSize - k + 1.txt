### 解题思路
滑动窗口的个数为numsSize - k + 1

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* 滑动窗口的最大值 */
int findMax(int *arr, int i, int j)
{
    int max = arr[i];

    for (int k = i + 1; k <= j; k++) {
        max = max < arr[k] ? arr[k] : max;
    }

    return max;
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    if ((nums == NULL) || (numsSize == 0)) {
        *returnSize = 0;
        return nums;
    }

    int index = 0;
    int *arr = (int *)malloc(sizeof(int) * numsSize);
    memset(arr, 0x0, sizeof(int) * numsSize);

    for (int i = 0; i < numsSize - k + 1; i++) {
        arr[index++] = findMax(nums, i, i + k - 1);
    }

    *returnSize = index;
    return arr;
}
```