### 解题思路
方法一：暴力破解

方法二：贪心算法
从数组0开始遍历，更大值=MAX(更大值+当前值，当前值)
最大值=更大值中最大的值
### 代码

```c
//贪心算法
//从数组0开始遍历，更大值=MAX(更大值+当前值，当前值)
//最大值=更大值中最大的值
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maxSubArray(int* nums, int numsSize){
    int     i       = 0;
    int     iMax    = nums[0];
    int     iBig    = nums[0];

    for (i = 1; i < numsSize; i++)
    {
        iBig = MAX(iBig + nums[i], nums[i]);
        if (iBig > iMax)
        {
            iMax = iBig;
        }
    }
    return iMax;
}

/*
//方法一：暴力破解
int maxSubArray(int* nums, int numsSize){
    int     i       = 0;
    int     j       = 0;
    int     iMax    = nums[0];
    int     iTmp    = 0;

    for (i = 0; i < numsSize; i++)
    {
        iTmp = 0;
        for (j = i; j < numsSize; j++)
        {
            iTmp += nums[j];
            if (iTmp > iMax)
            {
                iMax = iTmp;
            }
        }
    }

    return iMax;
}

*/
```