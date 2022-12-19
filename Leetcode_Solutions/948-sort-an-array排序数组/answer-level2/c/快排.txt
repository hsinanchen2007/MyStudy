### 解题思路

### 代码

```c
int* sortArray(int* nums, int numsSize, int* returnSize)
{
    int lo = 0, hi = numsSize-1;
    int movel = 0;
    while(lo < hi  && numsSize > 1)
    {
        if(nums[lo] > nums[hi])
        {
            int temp = nums[lo];
            nums[lo] = nums[hi];
            nums[hi] = temp;
            movel = !movel;
        }
        if(movel)
            lo++;
        else
            hi--;
    }

    if(hi > 0)
        sortArray(nums,hi, returnSize);
    if(numsSize-lo-1 > 0)
        sortArray(nums+lo+1,numsSize-lo-1, returnSize);

    *returnSize = numsSize;
    return nums;
}
```