### 解题思路
暴力循环，两个for循环一个加一个尝试，定义一个结果数组用来装结果

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i,j;
    int *result = (int*)malloc(2*sizeof(int));
    bool found = false;
    for(i=0;i<numsSize-1;i++)
    {
        if(!found)
        {
            for(j=i+1;j<numsSize;j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    result[0] = i;
                    result[1] = j;
                    found = true;
                    break;
                }
            }           
        }
    }
    if(found)
    *returnSize = 2;
    else
    *returnSize = 0;
    return result;
}
```