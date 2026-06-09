### 解题思路
方法一：通过和 nums[0]比较，分两段进行循环比较
方法二：二分法
分三种情况，考虑 左指针右移的条件
    1, 三指针都在同一顺序的一侧
    2, mid 指针在前半部分中
    3, mid 指针在后半部分中
### 代码

```c
//方法二：二分法
//分三种情况，考虑 左指针右移的条件
//1, 三指针都在同一顺序的一侧
//2, mid 指针在前半部分中
//3, mid 指针在后半部分中
int search(int* nums, int numsSize, int target){
    int     iLeft       = 0;
    int     iRight      = 0;
    int     iMid        = 0;
    int     iRet        = -1;

    if ((NULL == nums) || (0 == numsSize))
    {
        return iRet;
    }

    if (1 == numsSize)
    {
        iRet = (nums[0] == target) ? 0 : -1;
        return iRet;
    }

    iLeft = 0;
    iRight = numsSize - 1;
    
    while (iLeft <= iRight){
        iMid = (iLeft + iRight) / 2;

        if (nums[iMid] == target)
        {
            iRet = iMid;
            break;
        }

//        printf("[1] left=%d-%d, mid=%d-%d, right=%d-%d, target=%d\n", iLeft, nums[iLeft], iMid, nums[iMid], iRight, nums[iRight], target);

        if((((nums[iLeft] <= nums[iMid]) && (nums[iMid] <= nums[iRight])) && (nums[iMid] < target)) ||
            (((nums[iLeft] <= nums[iMid]) && (nums[iMid] > nums[iRight])) && ((nums[iLeft] > target) || (nums[iMid] < target))) ||
            ((nums[iLeft] > nums[iMid]) && (nums[iMid] <= nums[iRight]) && ((nums[iMid] < target) && (nums[iLeft] > target))))
        {
            //第一种情况
            iLeft = iMid + 1;
        }
        else
        {
            //第二种情况
            iRight = iMid - 1;
        }

//        printf("[2] left=%d, mid=%d, right=%d, target=%d\n", iLeft, iMid, iRight, target);
    }
    return iRet;
}


/*
//方法一：通过和 nums[0]比较，分两段进行循环比较
int search(int* nums, int numsSize, int target){
    int     i       = 0;
    int     j       = 0;
    int     iTmp    = 0;
    int     iRet    = -1;

    if ((NULL == nums) || (0 == numsSize))
    {
        return iRet;
    }

    if (nums[0] <= target)
    {
        //目标值在前半段
        for (i = 0; i < numsSize; i++)
        {
            if (nums[i] == target)
            {
                iRet = i;
                break;
            }

            if ((i + 1 < numsSize) && (nums[i] > nums[i + 1]))
            {
                break;
            }
        }
    }
    else
    {
        //目标值在后半段
        for (j = numsSize - 1; j > 0; j--)
        {
            if (nums[j] == target)
            {
                iRet = j;
                break;
            }

            if ((j - 1 >= 0) && (nums[j - 1] > nums[j]))
            {
                break;
            }
        }
    }
    return iRet;
}
*/
```