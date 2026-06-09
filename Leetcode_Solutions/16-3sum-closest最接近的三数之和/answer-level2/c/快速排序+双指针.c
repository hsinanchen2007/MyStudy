### 解题思路
1，快速排序 qsort() 将输入数组从小到大排序
2，双指针操作，
    当前和大于目标值则右指针左移
    当前和小于目标值则左指针右移
    当前和等于目标值则直接返回
3，优化
    当中间值相等时，则左右指针则不需要从两边开始

### 代码

```c
int compare(const void *a, const void *b)
{
    return *((int*)(a)) - *((int*)(b));
}

int threeSumClosest(int* nums, int numsSize, int target){
    int     iNear       = 0;    //最接近之和
    int     iNearSub    = 0;    //最接近之和与目标之差的绝对值

    int     iSubAbs     = 0;    //三数之和与目标差的绝对值
    int     iTmpAdd     = 0;    //三数之和

    int     iLeft       = 0;
    int     i           = 1;
    int     iRight      = numsSize - 1;

    if ((NULL == nums) || (0 == numsSize))
    {
        return iNear;
    }

    //1：对整数数组排序
    qsort(nums, numsSize, sizeof(int), compare);

/*
    for (i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    i = 1;
*/
    iNear = nums[iLeft] + nums[i] + nums[iRight];
    iNearSub = abs(iNear - target);

    //2：对撞指针
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            iLeft = 0;
            iRight = numsSize - 1;
        }

        while ((iLeft < i) && (iRight > i))
        {
            iTmpAdd = nums[iLeft] + nums[i] + nums[iRight];
            iSubAbs = abs(iTmpAdd - target);

//            printf("iLeft=%d, i=%d, iRight=%d, sum=[%d][%d], abs=[%d][%d]\r\n", iLeft, i, iRight, iTmpAdd, iNear, iSubAbs, iNearSub);

            if (iSubAbs <= iNearSub)
            {
                //当前和更接近目标值
                iNear = iTmpAdd;
                iNearSub = iSubAbs;
            }

            if (iTmpAdd > target)
            {
                //当前和大于目标值则右指针左移
                iRight -= 1;
            }
            else if (iTmpAdd < target)
            {
                //当前和小于目标值则左指正右移
                iLeft += 1;
            }
            else
            {
                //如果相等，则直接返回
                return iNear;
            }
        }
    }

    return iNear;
}
```