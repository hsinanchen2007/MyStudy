### 解题思路
此处撰写解题思路

### 代码

```c
int Compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int Max(int a, int b)
{
    return a > b ? a : b;
}

int maximumProduct(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), Compare);
    return Max(nums[numsSize - 1] * nums[numsSize -2] * nums[numsSize - 3], nums[numsSize - 1] * nums[0] * nums[1]);
}
```