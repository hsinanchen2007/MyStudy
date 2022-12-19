### 解题思路
第一次使用leetcode刷题，不太懂动态内存管理和释放的问题，参考了讨论区的代码，学到了。
但这种解法都是基于假设的情况下的。存在拓展的探讨的空间。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
int i=0,j;
int *result_nums;
for (;i<numsSize;i++)
{
    for (j=i+1;j<numsSize;j++)
    {
        if((nums[i]+nums[j])==target)
        {
                *returnSize = 2;
                result_nums = (int*)malloc(sizeof(int)* 2);
                result_nums[0] = i;
                result_nums[1] = j;
                return result_nums;
        }
    }
}
return 0;
}
```