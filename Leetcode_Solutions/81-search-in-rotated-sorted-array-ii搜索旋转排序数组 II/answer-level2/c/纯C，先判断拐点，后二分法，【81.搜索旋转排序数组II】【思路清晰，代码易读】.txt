### 解题思路
方法一：
1,找到拐点，判断目标值在拐点前半部分还是在后半部分
2,二分法找到目标值

### 代码

```c

//方法一：
//1,找到拐点，判断目标值在拐点前半部分还是在后半部分
//2,二分法找到目标值

bool dichSearch(int* nums, int iLeft, int iRight, int target){
    bool    bRet        = false;
    int     iMid        = 0;

    while(iLeft <= iRight)
    {
        iMid = (iLeft + iRight) / 2;
        if (nums[iMid] == target)
        {
            return true;
        }
        else if (nums[iMid] > target)
        {
            iRight = iMid - 1;
        }
        else
        {
            iLeft = iMid + 1;
        }
    }

    return false;
}

bool search(int* nums, int numsSize, int target){
    int     i           = 0;
    int     iChange     = 0;

    if((NULL == nums) || (0 == numsSize)) return false;

    //1,寻找拐点
    for(i = 1; i < numsSize; i++)
    {
        if (nums[i] < nums[i - 1])
        {
            iChange = i - 1;
            break;
        }
        iChange = i;
    }

    //2,判断目标值在左半部分还是右半部分
    if (target == nums[iChange])
    {
        return true;
    }
    if (target > nums[iChange])
    {
        return false;
    }
    else
    {
        if (target == nums[0])
        {
            return true;
        }
        else if (target > nums[0])
        {
            return dichSearch(nums, 0, iChange, target);
        }
        else
        {
            return dichSearch(nums, iChange + 1, numsSize - 1, target);
        }
    }
}
```