### 解题思路
方法一：暴力法(超时)
1,循环遍历数组
2,求每一个 i 对应的左边 iLeft 和右边 iRight
3,计算每一个i对应的矩形面积，求出其中最大值

方法二：单调栈(学习)
1,使用数组 StackArray 模拟栈的使用
2,如果 heights[i] > heights[i+1] 则将 栈中所有大于 heights[i+1]的 元素出栈，并计算最大面积
3,如果 heights[i] <= heights[i+1] 则将  元素入栈
4,最后将栈中所有元素出栈，并计算最大面积

方法三：动态规划算法优化(无解)
花了很多心思在动态规划算法的优化上，最后发现无法优化达到要求。
### 代码

```c
//方法二：单调栈(学习)
//1,使用数组 StackArray 模拟栈的使用
//2,如果 heights[i] > heights[i+1] 则将 栈中所有大于 heights[i+1]的 元素出栈，并计算最大面积
//3,如果 heights[i] <= heights[i+1] 则将  元素入栈
//4,最后将栈中所有元素出栈，并计算最大面积

#define     MAX_II(a, b)        ((a) > (b) ? (a) : (b))
int largestRectangleArea(int* heights, int heightsSize){
    int     i           = 0;
    int     iTop        = 0;
    int     iTmpMax     = 0;
    int     iTmpCur     = 0;
    int*    pHeight     = NULL;
    int     StackArray[heightsSize + 2];

    if((NULL == heights) || (0 == heightsSize)) return 0;

    pHeight = (int*)malloc(sizeof(int) * (heightsSize + 2));
    memset(pHeight, 0x00, sizeof(int) * (heightsSize + 2));
    memcpy(&pHeight[1], &heights[0], sizeof(int) * heightsSize);

    memset(StackArray, 0x00, sizeof(int) * (heightsSize + 2));

    //1, 默认栈底 StackArray[0]=0 
    iTop = 1;

    //调换2，3的顺序，简化操作，先判断元素是否可以直接出栈计算面积，并且将栈能出栈的都出栈
    for(i = 1; i <= heightsSize + 1; i++)
    {        
        //3,出栈操作
        while(pHeight[StackArray[iTop - 1]] > pHeight[i])
        {
            iTmpCur = (i - StackArray[iTop - 2] - 1) * pHeight[StackArray[iTop - 1]];
            iTmpMax = MAX_II(iTmpCur, iTmpMax);

            iTop -= 1;
        }

        //2,入栈操作
        StackArray[iTop] = i;
        iTop += 1;
    }
    
    return iTmpMax;
}




/*
//方法一：暴力法
//1,循环遍历数组
//2,求每一个 i 对应的左边 iLeft 和右边 iRight
//3,计算每一个i对应的矩形面积，求出其中最大值

#define     MAX_III(a, b, c)    ((a) > ((b) > (c) ? (b) : (c)) ? (a) : ((b) > (c) ? (b) : (c)))
#define     MAX_II(a, b)        ((a) > (b) ? (a) : (b))
#define     MIN(a, b)           ((a) < (b) ? (a) : (b))

int largestRectangleArea(int* heights, int heightsSize){
    int     i           = 0;
    int     j           = 0;
    int     iLeft       = 0;
    int     iRight      = 0;
    int     iTmpMax     = 0;
    int     iTmpCur     = 0;
    int*    pHeight     = NULL;

    if((NULL == heights) || (0 == heightsSize)) return 0;

    pHeight = (int*)malloc(sizeof(int) * (heightsSize + 2));
    memset(pHeight, 0x00, sizeof(int) * (heightsSize + 2));
    memcpy(&pHeight[1], &heights[0], sizeof(int) * heightsSize);

    for(i = 1; i <= heightsSize; i++)
    {
        //1,求左边
        for(j = i - 1; j >= 0; j--)
        
            if(pHeight[j] < pHeight[i])
            {
                iLeft = j;
                break;
            }
        }

        //2,求右边
        for(j = i + 1; j <= heightsSize + 1; j++)
        {
            if(pHeight[j] < pHeight[i])
            {
                iRight = j;
                break;
            }
        }

        //3,求面积
        iTmpCur = (iRight - iLeft - 1) * pHeight[i];
        iTmpMax = MAX_II(iTmpCur, iTmpMax);
    }

    return iTmpMax;
}
*/

/*
//方法三：动态规划算法优化
//1,如何求dp[i][j]， 
//2, if(i<heights[i-1])   dp[i][j]=max(dp[i][j-1],dp[i-1][heights[i-1]], S[i][j])
//3, S[i][j]为以i,j为坐标往前找能画出的最大面积
//优化 dp[][],  dp[i][j-1],dp[i-1][heights[i-1]] 两个值都可以用临时变量代替
//解决 dp 空间问题

//优化循环处理，解决时间超时问题，j没有必要从1开始执行
//设置两个锚点，
//1,一个就是整个数组中最小值，每个 i 都需要计算一次最小j 时的面积
//2,一个就是当前j前面一个拐点，就是前面柱状图由低变高的拐点


//计算步骤：
//1,每个 i 的值都计算用 pHeight[1] 到 pHeight[i] 计算矩形面积

//问题，随着I的增加，循环次数增加，每次找左边的时间增加，导致超时
//优化，能不能把左边 k 通过每次本身的循环就固定下来

#define     MAX_III(a, b, c)    ((a) > ((b) > (c) ? (b) : (c)) ? (a) : ((b) > (c) ? (b) : (c)))
#define     MAX_II(a, b)        ((a) > (b) ? (a) : (b))
#define     MIN(a, b)           ((a) < (b) ? (a) : (b))
#define     MAXNUM              20000

int largestRectangleArea(int* heights, int heightsSize){
    int     i           = 0;
    int     j           = 0;
    int     k           = 0;
    int     iTmpS       = 0;
    int     iTmpMax     = 0;
    int     iTmpCur     = 0;
    int*    pHeight     = NULL;
    int*    pTmpK       = NULL;
    bool    bFlag       = true;

    if((NULL == heights) || (0 == heightsSize)) return 0;

    pHeight = (int*)malloc(sizeof(int) * (heightsSize + 2));
    memset(pHeight, 0x00, sizeof(int) * (heightsSize + 2));
    memcpy(&pHeight[1], &heights[0], sizeof(int) * heightsSize);

    pTmpK = (int*)malloc(sizeof(int) * (heightsSize + 1));
    memset(pTmpK, 0x00, sizeof(int) * (heightsSize + 1));

    for(i = 1; i <= heightsSize; i++)
    {
        if((bFlag) && (pHeight[i] == 1))
        {
            iTmpCur += pHeight[i];
            iTmpMax = MAX_II(iTmpCur, iTmpMax);
            continue;
        }
        bFlag = false;

        //计算 pHeight[1] 到 pHeight[i] 的矩形面积
        for(j = 1; j <= i; j++)
        {
            if(pHeight[i] < pHeight[i - 1])
            {
                if(pHeight[j] > pHeight[i])
                {
                    pTmpK[j] = i;
                }
                else
                {
                    for(k = i - 1; k > 0; k--)
                    {
                        if(pHeight[k] < pHeight[j])
                        {
                            break;
                        }
                        else
                        {
                            pTmpK[k] = i;
                        }
                    }
                    pTmpK[j] = k;
                }
            }
            else
            {
                if(pHeight[j] > pHeight[i])
                {
                    pTmpK[j] = i;
                }
                pTmpK[i] = i - 1;
            }

            iTmpS = (i - pTmpK[j]) * MIN(pHeight[i], pHeight[j]);
            iTmpCur = MAX_III(iTmpCur, iTmpMax, iTmpS);
        }

        iTmpMax = MAX_II(iTmpCur, iTmpMax);
    }

    return iTmpMax;
}
*/
/*
#define     MAX_III(a, b, c)    ((a) > ((b) > (c) ? (b) : (c)) ? (a) : ((b) > (c) ? (b) : (c)))
#define     MAX_II(a, b)        ((a) > (b) ? (a) : (b))
#define     MIN(a, b)           ((a) < (b) ? (a) : (b))

int largestRectangleArea(int* heights, int heightsSize){
    int     i           = 0;
    int     j           = 0;
    int     k           = 0;
    int     iTmpS       = 0;
    int     iTmpMax     = 0;
    int     iTmpCur     = 0;
    int*    pHeight     = NULL;

    if((NULL == heights) || (0 == heightsSize)) return 0;

    pHeight = (int*)malloc(sizeof(int) * (heightsSize + 2));
    memset(pHeight, 0x00, sizeof(int) * (heightsSize + 2));
    memcpy(&pHeight[1], &heights[0], sizeof(int) * heightsSize);

    for(i = 1; i <= heightsSize; i++)
    {
        //计算 pHeight[1] 到 pHeight[i] 的矩形面积
        for(j = 1; j <= i; j++)
        {
            for(k = i - 1; k > 0; k--)
            {
                if(pHeight[k] < pHeight[j])
                {
                    break;
                }
            }

            iTmpS = (i - k) * MIN(pHeight[i], pHeight[j]);
            iTmpCur = MAX_III(iTmpCur, iTmpMax, iTmpS);

//            printf("[2][i=%d][j=%d][k=%d][iTmpS=%d][iTmpCur=%d][iTmpMax=%d]\n", 
//                    i, j, k, iTmpS, iTmpCur, iTmpMax);
        }

        iTmpMax = MAX_II(iTmpCur, iTmpMax);
    }

    return iTmpMax;
}
*/


/*
//计算步骤：
//1,计算最小高度是的面积
//2,计算拐点时的面积
//3,拐点后按照 pHeight[k] 的值进行跳跃式计算


//需要记录图形中每一个拐点，每一个i 时，需要计算每个拐点的面积，
//1,首先需要计算每一个拐点的面积
//2,然后再以最后一个拐点后，按照 pHeight[k] 的值进行跳跃式计算

#define     MAX_III(a, b, c)    ((a) > ((b) > (c) ? (b) : (c)) ? (a) : ((b) > (c) ? (b) : (c)))
#define     MAX_II(a, b)        ((a) > (b) ? (a) : (b))
#define     MIN(a, b)           ((a) < (b) ? (a) : (b))

struct  TrunPoint {
    int     iTrunI;
    int     iTrunJ
};


int largestRectangleArea(int* heights, int heightsSize){
    int     i           = 0;
    int     j           = 0;
    int     k           = 0;
    int     iTmpS       = 0;
    int     iTmpMax     = 0;
    int     iTmpCur     = 0;
    int*    pHeight     = NULL;

    int     iNum        = 0;
    int     iPointNum   = 0;
    struct  TrunPoint*      pTrunPoint      = NULL;

    if((NULL == heights) || (0 == heightsSize)) return 0;

    pHeight = (int*)malloc(sizeof(int) * (heightsSize + 2));
    memset(pHeight, 0x00, sizeof(int) * (heightsSize + 2));
    memcpy(&pHeight[1], &heights[0], sizeof(int) * heightsSize);

    pTrunPoint = (struct TrunPoint*)malloc(sizeof(struct TrunPoint) * (heightsSize + 1));
    memset(pTrunPoint, 0x00, sizeof(struct TrunPoint) * (heightsSize + 1));

    pTrunPoint[0].iTrunI = 0;
    pTrunPoint[0].iTrunI = 0;
    iPointNum = 1;

    for(i = 1; i <= heightsSize; i++)
    {
        if(0 == pHeight[i - 1])
        {
            iTmpCur = pHeight[i];
            iTmpMax = MAX_II(iTmpCur, iTmpMax);
            continue;
        }

        if((pHeight[i] <= pHeight[i - 1]) && (pHeight[i] < pHeight[i + 1])) 
        {
            pTrunPoint[iPointNum].iTrunI = i;
            pTrunPoint[iPointNum].iTrunJ = pHeight[i];
            iPointNum += 1;

            printf("[0][Num=%d][i=%d][j=%d]\n", iPointNum, i, pHeight[i]);
        }

        if(iPointNum > 1)
        {
            //计算所有拐点面积
            for(iNum = 1; iNum < iPointNum; iNum++)
            {
                j = pTrunPoint[iNum].iTrunJ;
                if (j <= pHeight[i])
                {
                    for(k = i - 1; k > 0; k--)
                    {
                        if(pHeight[k] < j)
                        {
                            break;
                        }
                    }

                    iTmpS = (i - k) * j;
                    iTmpCur = MAX_III(iTmpCur, iTmpMax, iTmpS);

                    printf("[1][Num=%d][iTrunI=%d][iTrunJ=%d][i=%d][j=%d][k=%d][iTmpS=%d][iTmpCur=%d][iTmpMax=%d]\n", 
                            iNum, pTrunPoint[iNum].iTrunI, pTrunPoint[iNum].iTrunJ, i, j, k, iTmpS, iTmpCur, iTmpMax);
                }
            }
        }

        //计算最后一个拐点之后的所有 i 的面积
        for(j = pTrunPoint[iPointNum - 1].iTrunJ + 1; j <= pHeight[i]; j++)
        {
            for(k = i - 1; k > 0; k--)
            {
                if(pHeight[k] < j)
                {
                    break;
                }
            }

            j = MIN(pHeight[k + 1], pHeight[i]);
            iTmpS = (i - k) * j;
            iTmpCur = MAX_III(iTmpCur, iTmpMax, iTmpS);

            printf("[2][i=%d][j=%d][k=%d][iTmpS=%d][iTmpCur=%d][iTmpMax=%d]\n", 
                    i, j, k, iTmpS, iTmpCur, iTmpMax);
        }

        iTmpMax = MAX_II(iTmpCur, iTmpMax);
    }

    return iTmpMax;
}
*/
/*
//方法二：动态规划算法优化
//1,如何求dp[i][j]， 
//2, if(i<heights[i-1])   dp[i][j]=max(dp[i][j-1],dp[i-1][heights[i-1]], S[i][j])
//3, S[i][j]为以i,j为坐标往前找能画出的最大面积
//优化 dp[][],  dp[i][j-1],dp[i-1][heights[i-1]] 两个值都可以用临时变量代替
//解决 dp 空间问题
#define     MAX_III(a, b, c)    ((a) > ((b) > (c) ? (b) : (c)) ? (a) : ((b) > (c) ? (b) : (c)))
#define     MAX_II(a, b)    ((a) > (b) ? (a) : (b))
int largestRectangleArea(int* heights, int heightsSize){
    int     i           = 0;
    int     j           = 0;
    int     k           = 0;
    int     iTmpS       = 0;
    int     iTmpMax     = 0;
    int     iTmpCur     = 0;
    int*    pHeight     = NULL;

    if((NULL == heights) || (0 == heightsSize)) return 0;

    pHeight = (int*)malloc(sizeof(int) * (heightsSize + 1));
    memset(pHeight, 0x00, sizeof(int) * (heightsSize + 1));
    memcpy(&pHeight[1], &heights[0], sizeof(int) * heightsSize);

    for(i = 1; i <= heightsSize; i++)
    {
        if(0 == pHeight[i - 1])
        {
            iTmpCur = pHeight[i];
            iTmpMax = MAX_II(iTmpCur, iTmpMax);
            continue;
        }
        for(j = 1; (j > 0) && (j <= pHeight[i]); j++)
        {
            for(k = i - 1; k > 0; k--)
            {
                if(pHeight[k] < j)
                {
                    break;
                }
            }

            iTmpS = (i - k) * j;
            iTmpCur = MAX_III(iTmpCur, iTmpMax, iTmpS);
        }

        iTmpMax = MAX_II(iTmpCur, iTmpMax);
    }

    return iTmpMax;
}
*/


/*
//方法一：动态规划算法
//1,如何求dp[i][j]， 
//2, if(i<heights[i-1])   dp[i][j]=max(dp[i][j-1],dp[i-1][heights[i-1]], S[i][j])
//3, S[i][j]为以i,j为坐标往前找能画出的最大面积
#define     MAX(a, b, c)    ((a) > ((b) > (c) ? (b) : (c)) ? (a) : ((b) > (c) ? (b) : (c)))
int largestRectangleArea(int* heights, int heightsSize){
    int     i       = 0;
    int     j       = 0;
    int     k       = 0;
    int     iHMax   = 1000;
    int     iTmpS   = 0;
    int     iHeight = 0;
    int     dp[heightsSize + 1][iHMax];
    int*    pHeight = NULL;

    if((NULL == heights) || (0 == heightsSize)) return 0;

    pHeight = (int*)malloc(sizeof(int) * (heightsSize + 1));
    memset(pHeight, 0x00, sizeof(int) * (heightsSize + 1));
    memcpy(&pHeight[1], &heights[0], sizeof(int) * heightsSize);
    memset(dp, 0x00, sizeof(int) * (heightsSize + 1) * iHMax);

    for(i = 1; i <= heightsSize; i++)
    {
        for(j = 0; j <= pHeight[i]; j++)
        {
            if(j == 0)
            {
                dp[i][j] = dp[i - 1][pHeight[i - 1]];
                continue;
            }

            for(k = i - 1; k > 0; k--)
            {
                if(pHeight[k] < j)
                {
                    break;
                }
            }

            iTmpS = (i - k) * j;
            
            printf("[1][i=%d][j=%d][k=%d][dp[%d][%d]=%d][dp[%d][%d]=%d][iTmpS=%d]\n", 
                    i, j, k, i, j - 1, dp[i][j - 1], i - 1, pHeight[i - 1], dp[i - 1][pHeight[i - 1]], iTmpS);

            dp[i][j] = MAX(dp[i][j - 1], dp[i - 1][pHeight[i - 1]], iTmpS);
        }
    }

    return dp[heightsSize][pHeight[heightsSize]];
}
*/



```