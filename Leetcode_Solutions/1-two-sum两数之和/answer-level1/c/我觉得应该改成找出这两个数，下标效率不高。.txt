### 解题思路
此处撰写解题思路
此题，我觉得应该改成找出这两个数，下标效率不高。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    if(nums == NULL || returnSize == NULL) return NULL;
    if(numsSize == 1 && target != *nums) return NULL;

    *returnSize = 0;
    int* ret = NULL;
    for(int i = 0; i < numsSize; ++i)
    {
        int sub = target - *(nums+i);
        for(int j = i + 1; j < numsSize; ++j)
        {
            if(*(nums+j) == sub)
            {
                ret = (int*)malloc(sizeof(int)*2);
                *(ret) = i;
                *(ret + 1) = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    return NULL;
}
```