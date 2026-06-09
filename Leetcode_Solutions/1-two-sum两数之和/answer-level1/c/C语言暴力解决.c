### 解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *rv = (int*)malloc(sizeof(int)*numsSize);
    
    if(rv == NULL)
    {
        return 0;
    }

    for(int i=0; i<numsSize; i++)
    {
        for(int j=i+1; j<numsSize;j++)
        {
            if((nums[i] + nums[j]) == target)
            {
                rv[0] = i;
                rv[1] = j;
                *returnSize = 2;
                return rv;
            }
        }
    }

    return 0;
}
```