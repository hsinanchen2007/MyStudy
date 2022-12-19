### 解题思路
第一次使用暴力搜索算法，总是超出时间限制。参考了别人的解法，看到了双指针解法的巧妙，

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    
    int *rel = (int*)malloc(sizeof(int)*2);
    memset(rel, 0, sizeof(int)*2);

    int i =0, j = numsSize-1;
    while(i <j)
    {
        if(nums[i] + nums[j] == target)
        {
            rel[0] = nums[i];
            rel[1] = nums[j];
            break;
        }
        else if(nums[i] + nums[j] >target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    *returnSize = 2;
    return rel;
}
```