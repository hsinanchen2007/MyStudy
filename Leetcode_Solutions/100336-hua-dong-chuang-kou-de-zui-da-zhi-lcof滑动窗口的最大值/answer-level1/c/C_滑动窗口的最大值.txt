### 解题思路
暴力法

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){

    if(numsSize==0)
    {
        *returnSize=0;
        return 0;
    }

    *returnSize=numsSize-k+1;
    int* result=(int*)malloc(sizeof(int)**returnSize);
    for(int i=0;i<*returnSize;++i)
    {
        result[i]=((unsigned)1)<<(sizeof(int)*8-1);
        for(int j=0;j<k;++j)
            if(nums[i+j]>result[i])
                result[i]=nums[i+j];
    }
    return result;
}
```