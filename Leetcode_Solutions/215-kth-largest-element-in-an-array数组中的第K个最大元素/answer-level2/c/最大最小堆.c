### 解题思路
解法一：用qsort函数解决，代码简单

### 代码

```c
int comp(const void *a, const void *b)
{
    return *(int *)a < *(int *)b;
}

int findKthLargest(int* nums, int numsSize, int k){

    qsort(nums, numsSize, sizeof(int), comp);

    return nums[k - 1];
}
```