### 解题思路
方法一：暴力破解

方法二：贪心算法
从数组0开始遍历，更大值=MAX(更大值+当前值，当前值)
最大值=更大值中最大的值

方法三：分治算法
1,结束条件，当numsSize==1时直接返回当前值
2,处理左支 求 Max_Left
3,处理右支 求 Max_Right
4,处理本身，向左求最大和Max_l 然后 向右求最大和Max_r
5,最终结果为 MAX(Max_Left, Max_Right, Max_r)

### 代码

```c
//方法三：分治算法
//1,结束条件，当numsSize==1时直接返回当前值
//2,处理左支 求 Max_Left
//3,处理右支 求 Max_Right
//4,处理本身，向左求最大和Max_l 然后 向右求最大和Max_r
//5,最终结果为 MAX(Max_Left, Max_Right, Max_r)
#define     MAX(a, b, c)    ((a) > ((b) > (c) ? (b) : (c)) ? (a) : ((b) > (c) ? (b) : (c)))
int maxSubArray(int* nums, int numsSize){
    int     i               = 0;
    int     iTmp            = 0;
    int     Max_Left        = 0;
    int     Max_Right       = 0;
    int     Max_l           = 0;
    int     Max_r           = 0;

    //1,结束条件
    if ((0 == numsSize) || (1 == numsSize))
    {
        return nums[0];
    }
    else
    {
        //2,求左支
        Max_Left = maxSubArray(&nums[0], (numsSize - 1) / 2);
        //3,求右支
        Max_Right = maxSubArray(&nums[(numsSize + 1) / 2], numsSize / 2);
    }

    //4,求中间
    iTmp = 0;
    Max_l = nums[(numsSize - 1) / 2];
    for (i = (numsSize - 1) / 2; i >= 0; i--)
    {
        iTmp += nums[i];
        if (iTmp > Max_l)
        {
            Max_l = iTmp;
        }
    }

    iTmp = Max_l;
    Max_r = Max_l;
    for (i = (numsSize + 1) / 2; i < numsSize; i++)
    {
        iTmp += nums[i];
        if (iTmp > Max_r)
        {
            Max_r = iTmp;
        }
    }

//    printf("[M_L=%d][M_R=%d][ml=%d][mr=%d]\n", Max_Left, Max_Right, Max_l, Max_r);
    //5,返回最大值
    return MAX(Max_Left, Max_Right, Max_r);
}


/*
//方法二：贪心算法
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
*/
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