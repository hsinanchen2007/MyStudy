### 解题思路
采用冒泡排序类似的思路计算两个数之和是否满足需求，满足则可返回结果。注意：返回值必须是通过malloc申请的内存（堆空间）。

### 代码

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    int *res = (int *)malloc(sizeof(int)*2);

    for(i = 0; i < numsSize; ++i)
    {
        for(j = i + 1; j < numsSize; ++j)
        {
            if(nums[i] + nums[j] == target)
            {
                res[0] = i;
                res[1] = j;
                *returnSize = 2;
                return (int *)res;
            }
            
        }
    }
    return (int *)res;
}


```