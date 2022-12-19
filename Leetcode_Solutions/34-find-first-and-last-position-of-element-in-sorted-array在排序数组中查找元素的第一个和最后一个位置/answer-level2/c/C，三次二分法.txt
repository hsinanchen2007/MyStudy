### 解题思路
方法一：
1，二分法找到结果
2，以mid为中心向两边找到边界

方法二：
1，使用二分法判断是否存在目标值
2，使用二分法找到第一个 小于等于 target 的位置
3，使用二分法找到第一个 大于等于 target 的位置

注：
二分法精髓：iMid=(iLeft+iRight)/2 则每次 iMid 取值偏向 iLeft
二分法精髓：iMid=(iLeft+iRight+1)/2 则每次 iMid 取值偏向 iRight

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//二分法查找 target 值
bool binarySearch(int* nums, int numsSize, int target){
    int     iLeft       = 0;
    int     iMid        = 0;
    int     iRight      = 0;
    bool    bRet        = false;

    iLeft = 0;
    iRight = numsSize - 1;

    while(iLeft <= iRight)
    {
        iMid = (iLeft + iRight) / 2;
        if (nums[iMid] == target)
        {
            bRet = true;
            break;
        }

        if (nums[iMid] < target)
        {
            iLeft = iMid + 1;
        }
        else
        {
            iRight = iMid - 1;
        }
    }
//    printf("[1] mid=%d\n", iMid);
    return bRet;
}

//二分法查找第一个 小于等于target的数
int binarySearchLess(int* nums, int numsSize, int target){
    int     iLeft       = 0;
    int     iMid        = 0;
    int     iRight      = 0;
    bool    bRet        = false;

    iLeft = 0;
    iRight = numsSize - 1;

    while(iLeft < iRight)
    {
        iMid = (iLeft + iRight) / 2;        //二分法精髓：iMid=(iLeft+iRight)/2 则每次 iMid 取值偏向 iLeft

        if (nums[iMid] >= target)
        {
            iRight = iMid;
        }
        else
        {
            iLeft = iMid + 1;
        }

//        printf("[2] left=%d, mid=%d, right=%d\n", iLeft, iMid, iRight);
    }
    return iLeft;
}

//二分法查找第一个大于等于 target 的数
int binarySearchGreater(int* nums, int numsSize, int target){
    int     iLeft       = 0;
    int     iMid        = 0;
    int     iRight      = 0;
    bool    bRet        = false;

    iLeft = 0;
    iRight = numsSize - 1;

    while(iLeft < iRight)
    {
        iMid = (iLeft + iRight + 1) / 2;        //二分法精髓：iMid=(iLeft+iRight+1)/2 则每次 iMid 取值偏向 iRight

        if (nums[iMid] <= target)
        {
            iLeft = iMid;
        }
        else
        {
            iRight = iMid - 1;
        }

//        printf("[3] left=%d, mid=%d, right=%d\n", iLeft, iMid, iRight);
    }
    return iRight;
}

//方法二：
//1，使用二分法判断是否存在目标值
//2，使用二分法找到第一个 小于等于 target 的位置
//3，使用二分法找到第一个 大于等于 target 的位置
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int*    pRet        = NULL;
    
    pRet = (int *)malloc(sizeof(int) * 2);
    pRet[0] = -1;
    pRet[1] = -1;
    *returnSize = 2;

    //1，使用二分法判断是否存在目标值
    if (binarySearch(nums, numsSize, target))
    {
        //2，使用二分法找到第一个 小于等于 target 的位置
        pRet[0] = binarySearchLess(nums, numsSize, target);

        //3，使用二分法找到第一个 大于等于 target 的位置
        pRet[1] = binarySearchGreater(nums, numsSize, target);
    }
    return pRet;
}


/*
//方法一：
//1，二分法找到结果
//2，以mid为中心向两边找到边界
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int*    pRet        = NULL;
    int     iLeft       = 0;
    int     iMid        = 0;
    int     iRight      = 0;
    bool    bFlag       = false;
    bool    bLFlag      = false;
    bool    bRFlag      = false;

    pRet = (int *)malloc(sizeof(int) * 2);
    pRet[0] = -1;
    pRet[1] = -1;
    *returnSize = 2;

    iLeft = 0;
    iRight = numsSize - 1;

    while(iLeft <= iRight)
    {
        iMid = (iLeft + iRight) / 2;

        if (nums[iMid] == target)
        {
            bFlag = true;
            break;
        }
        
        if (nums[iMid] < target)
        {
            iLeft = iMid + 1;
        }
        else
        {
            iRight = iMid - 1;
        }
    }

    if (bFlag)
    {
        iLeft = iMid;
        iRight = iMid;
        while(1)
        {
            if ((iLeft > 0) && (nums[iLeft - 1] == target))
            {
                iLeft -= 1;
            }
            else
            {
                pRet[0] = iLeft;
                bLFlag = true;
            }

            if ((iRight < numsSize - 1) && (nums[iRight + 1] == target))
            {
                iRight += 1;
            }
            else
            {
                pRet[1] = iRight;
                bRFlag = true;
            }

            if (bLFlag && bRFlag)
            {
                break;
            }
        }
    }

    return pRet;
}
*/
```