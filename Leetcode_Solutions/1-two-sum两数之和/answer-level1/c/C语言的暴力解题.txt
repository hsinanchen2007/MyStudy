### 解题思路
C语言的暴力解题，效率太低了。
自我勉励吧，各位C语言的同学们加油。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i=0;
    int j=numsSize-1;
    int *puiresult = (int*)malloc(sizeof(int) * 2);

    for(; j>0 ; j--)
    {
        for(i=0; i<j; i++)
        {
            if(nums[i] + nums[j] == target)
            {
                puiresult[0] = i;
                puiresult[1] = j;
                *returnSize = 2;
                return puiresult;
            }
        }
    }
    
    return 0;
}
```