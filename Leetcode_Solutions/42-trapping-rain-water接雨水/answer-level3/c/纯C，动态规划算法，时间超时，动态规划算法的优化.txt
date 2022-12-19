### 解题思路
方法一：动态规划算法，不仅超时，而且消耗空间大
1,建立 dp[][] 保存不同状态下的雨水值
2,dp[i][j] i表示x轴增加1，j表示柱子的高度
3,当 j <= height[i-1] 时 dp[i][j] = dp[i-1][height[i-1]]
4,当 j > height[i-1] 时 求取 j 增加时能够增加多少水

方法二：动态规划算法，在方法一的基础上进行动态规划算法的优化
1,优化 dp ，减少使用空间,最后发现，只需要用一个值 iRet 保存当前结果就行
2,优化循环次数，避免时间超时
    优化一：j 从 height[i - 1] + 1 开始 到 ((j <= height[i]) && (j <= iMaxj)) 结束
    优化二：找到两个蓄水边之后直接计算里面的面积，然后寻找下一个边
### 代码

```c
#define     MIN(a, b)   (((a) < (b)) ? (a) : (b))
//方法二：动态规划算法，在方法一的基础上进行动态规划算法的优化
//1,优化 dp ，减少使用空间,最后发现，只需要用一个值 iRet 保存当前结果就行
//2,优化循环次数，避免时间超时
int trap(int* height, int heightSize){
    int         i               = 0;
    int         j               = 0;
    int         k               = 0;
    int         iMaxi           = 0;
    int         iMaxj           = 0;
    int         iTmp            = 0;
    int         iRet            = 0;

    if ((NULL == height) || (0 == heightSize)) return 0;

    //1,初始化
    iMaxi = 0;              //记录当前出现最大值时的i值
    iMaxj = height[0];      //记录当前出现最大值

    for (i = 1; i < heightSize; i++)
    {
        iTmp = i - 1;       //iTmp用于计算增加雨水时，指向对应的前一个蓄水边

        //优化一：j 从 height[i - 1] + 1 开始 到 ((j <= height[i]) && (j <= iMaxj)) 结束
        for(j = height[i - 1] + 1; ((j <= height[i]) && (j <= iMaxj)); j++)
        {
            //当 j 增加时，求增加的雨水，iTmp 指向对应的前一个蓄水边
            for (k = iTmp; k > iMaxi; k--)
            {
                if (height[k] >= j)
                {
                    iTmp = k;
                    break;
                }
            }

            //优化二：找到两个蓄水边之后直接计算里面的面积，然后寻找下一个边
            iRet += (i - k - 1) * (MIN(height[k], height[i]) - j + 1);
            j = MIN(height[k], height[i]);
        }

        if (height[i] >= iMaxj)
        {
            iMaxi = i;
            iMaxj = height[i];
        }
    }

    return iRet;
}

/*
//方法一：动态规划算法，不仅超时，而且消耗空间大
//1,建立 dp[][] 保存不同状态下的雨水值
//2,dp[i][j] i表示x轴增加1，j表示柱子的高度
//3,当 j <= height[i-1] 时 dp[i][j] = dp[i-1][height[i-1]]
//4,当 j > height[i-1] 时 求取 j 增加时能够增加多少水
int trap(int* height, int heightSize){
    int         i               = 0;
    int         j               = 0;
    int         k               = 0;
    int         iMaxi           = 0;
    int         iMaxj           = 0;
    int         dp[20000][50000];

    if ((NULL == height) || (0 == heightSize)) return 0;

    //1,初始化
    memset(dp, 0x00, sizeof(int) * 100 * 100);
    iMaxi = 0;
    iMaxj = height[0];

    for (i = 1; i < heightSize; i++)
    {
        for(j = 0; j <= height[i]; j++)
        {
            if (j <= height[i - 1])
            {
                dp[i][j] = dp[i - 1][height[i - 1]];
            }
            else
            {
                //当 j 增加时，求增加的雨水
                for (k = i - 1; k > iMaxi; k--)
                {
                    if (height[k] >= j)
                    {
                        break;
                    }
                }
                if (j <= iMaxj)
                {
                    dp[i][j] = dp[i][j - 1] + i - k - 1;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }

            printf("dp[%d][%d]=%d, iMax=%d, jMax=%d\n", i, j, dp[i][j], iMaxi, iMaxj);
        }

        if (height[i] >= iMaxj)
        {
            iMaxi = i;
            iMaxj = height[i];
        }
    }

    return dp[heightSize - 1][height[heightSize - 1]];
}
*/
```