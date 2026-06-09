### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int index = 0,indexN = 0;
    int *return_num;
    return_num = (int*)malloc(sizeof(int)*2);
    for(index = 0;index < numsSize; index++)
    {    
        for(indexN = index+1;indexN < numsSize;indexN++)
            if(nums[index] + nums[indexN] == target)
            {
                return_num[0] = index;
                return_num[1] = indexN;
                *returnSize = 2;
                return return_num;
            }
    }        
    return return_num; 
}
```