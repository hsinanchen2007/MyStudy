### 解题思路
此处撰写解题思路

### 代码

```c
int cmp(void *x, void *y)
{
    return *(int *)y - *(int *)x;
}

int findKthLargest(int* nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums[k - 1];
}

```