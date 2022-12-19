### 解题思路
方法一，使用系统函数 memmove 效率低下
方法二，使用快慢指针的做法

### 代码

```c
//方法二，使用双指针，快指针遍历数组，慢指针修改数组
int removeDuplicates(int* nums, int numsSize){
    int     pSlow   = 0;
    int     pFast   = 0;

    if ((NULL == nums) || (2 > numsSize))
    {
        return numsSize;
    }

    for (pFast = 1; pFast < numsSize; pFast++)
    {
        if (nums[pSlow] != nums[pFast])
        {
            pSlow += 1;
            if (pSlow != pFast)
            {
                //if条件为优化操作
                nums[pSlow] = nums[pFast];
            }
        }
    }
    return pSlow + 1;
}

/*
//方法一：遍历数组，使用memove 移动数组，效率低下
int removeDuplicates(int* nums, int numsSize){
    int     i           = 0;
    int     iRetNum     = numsSize;

    for (i = 0; i < iRetNum - 1; i++)
    {
//        printf("i=%d, nums=%d %d, iRetNum=%d\n", i, nums[i], nums[i + 1], iRetNum);
        if (nums[i] == nums[i + 1])
        {
            memmove(&nums[i], &nums[i + 1], sizeof(int) * (iRetNum - i - 1));
            iRetNum -= 1;
            i -= 1;
        }
    }
    return iRetNum;
}
*/
```