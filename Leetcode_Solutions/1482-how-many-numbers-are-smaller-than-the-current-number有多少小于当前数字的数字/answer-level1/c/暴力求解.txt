### 解题思路
此处撰写解题思路


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int *result = (int *)malloc(sizeof(int) * numsSize);
    memset(result, 0, sizeof(int) * numsSize);
    int index = 0;
    int cnt = 0;
    for(int i = 0; i <numsSize; i++)
    {
        for(int j = 0; j < numsSize; j++)
        {
            if(nums[i] > nums[j])
                cnt++;
        }
        result[index++] = cnt;
        cnt = 0;
    }
    *returnSize = numsSize;
    return result;
}
```