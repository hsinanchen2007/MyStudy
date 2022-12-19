### 解题思路
首先理解题意
之后很简单

### 代码

```c
comp(const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}
int arrayPairSum(int* nums, int numsSize)
{
    int i;
    int sum = 0;
    qsort(nums, numsSize, sizeof(int), comp);
    for(i = 0; i < numsSize; i = i + 2) {
        sum = sum + nums[i];
    }
    return sum;
}
```