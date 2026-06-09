### 解题思路
1，使用二分法找到mid
2，以mid为中心向两边找边界

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
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
```