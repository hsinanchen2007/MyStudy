### 解题思路
欢迎探讨,有问必答
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 0;
    int *result = NULL;
    if(numsSize>1)
        for(int i = 0; i<numsSize-1;i++)
        {
            for(int j = i+1; j<numsSize;j++)
            {
                if(nums[i]+nums[j] == target)
                {
                    result = (int*)malloc(sizeof(int)*2); 
                    if(result == NULL)
                        return NULL;
                    result[0] = i;
                    result[1]= j;
                    *returnSize = 2;
                    return result;
                }
                   
            }
        }
        return NULL;
}
```