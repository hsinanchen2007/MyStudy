### 解题思路
此处撰写解题思路
（1）首先计算待返回数组的大小numsSize - k + 1，并申请数组；
（2）依次移动数组，并计算每个小数组中的最大值并赋值给新申请的数组中

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_HTL(a, b) ((a) > (b) ? a : b)

int myMaxNum(int *arr, int begin, int end)
{
    int i;
    int max = arr[begin];
    
    for (i = begin; i < end; i++) {
        max = MAX_HTL(max, arr[i]);
    }

    return max;
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int *arr = NULL;
    int i;

    if (nums == NULL || k > numsSize || k <= 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numsSize - k + 1;
    arr = (int *)malloc(sizeof(int) * (*returnSize));

    for (i = 0; i <= numsSize - k; i++) {
        arr[i] = myMaxNum(nums, i, i + k);
    }

    return arr;
}
```