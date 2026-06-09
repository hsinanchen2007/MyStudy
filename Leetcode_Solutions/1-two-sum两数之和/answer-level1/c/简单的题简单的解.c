### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* ret = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;
    int i = 0;
    int j = 0;
    for(; i < numsSize - 1; i++){
        for(j = i + 1; j < numsSize; j++){
            if((nums[i] + nums[j]) == target){
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    return ret;
}
```