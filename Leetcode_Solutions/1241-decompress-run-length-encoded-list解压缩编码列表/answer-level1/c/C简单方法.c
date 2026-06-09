### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int* nums, int numsSize, int* returnSize)
{
    *returnSize = 0;
    int i,j,k = 0;
    for(i = 0;i < numsSize;i+=2)
    {
        *returnSize = *returnSize + nums[i];
    }
    int *result = (int *)malloc(*returnSize * sizeof(int));
    for(i = 1;i < numsSize;i+=2)
    {

        for(j = 0;j < nums[i-1];j++)
        {
            result[k] = nums[i];
            k++;
        }
    }
    return result;
}
```