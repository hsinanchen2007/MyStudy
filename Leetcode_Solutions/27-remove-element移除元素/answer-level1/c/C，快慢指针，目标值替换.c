### 解题思路
方法一：双指针法，参照26题，能够保持数据的顺序
方法二：替换最后元素法，找到目标值，直接和数组最后一个元素交换，并且减少数组个数
### 代码

```c

//方法二：替换最后元素法，找到目标值，直接和数组最后一个元素交换，并且减少数组个数
int removeElement(int* nums, int numsSize, int val){
    int     i       = 0;
    int     iNum    = numsSize;

    for (i = 0; i < iNum; i++)
    {
        if (nums[i] == val)
        {
            nums[i] = nums[iNum - 1];
            iNum -= 1;
            i -= 1;
        }
    }
    return iNum;
}


/*
//方法一：双指针法，参照26题，能够保持数据的顺序
int removeElement(int* nums, int numsSize, int val){
    int     pSlow   = 0;
    int     pFast   = 0;

    for (pFast = 0; pFast < numsSize; pFast++)
    {
        if (nums[pFast] != val)
        {
            if (pSlow != pFast)
            {
                nums[pSlow] = nums[pFast];
            }
            pSlow += 1;
        }
    }

    return pSlow;
}
*/
```