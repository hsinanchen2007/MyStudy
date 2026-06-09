### 解题思路
方法二：动态规划法
1,建立 dp[iCol] 个元素为 (left, right, height) 数组, left, right, height为当前位置最大的左边(坐标)，右边(坐标)，高
2,当matrix[i][j]=0时，dp[j](left, right, height)=(0,0,0)
3,当matrix[i][j]=1时，
  1）计算高   dp[j].height = dp_old[j].height+1
  2）计算左边 dp[j].left = max(dp_old[j].left, iCurLeft)  iCurLeft 为当前位置左边最近0点的坐标
  3）计算右边 dp[j].right = min(dp_old[j].right, iCurRight) iCurRight 为当前位置右边最近0点的坐标
4,计算当前行所有点的面积，计算最大面积

方法一的动态规划方法元素选择有问题，不能解决所有案例。

### 代码

```c
//方法二：动态规划法
//1,建立 dp[iCol] 个元素为 (left, right, height) 数组, left, right, height为当前位置最大的左边(坐标)，右边(坐标)，高
//2,当matrix[i][j]=0时，dp[j](left, right, height)=(0,0,0)
//3,当matrix[i][j]=1时，
//  1）计算高   dp[j].height = dp_old[j].height+1
//  2）计算左边 dp[j].left = max(dp_old[j].left, iCurLeft)  iCurLeft 为当前位置左边最近0点的坐标
//  3）计算右边 dp[j].right = min(dp_old[j].right, iCurRight) iCurRight 为当前位置右边最近0点的坐标
//4,计算当前行所有点的面积，计算最大面积

#define     MAX_II(a, b)        ((a) > (b) ? (a) : (b))
#define     MIN_II(a, b)        ((a) < (b) ? (a) : (b))

struct PointInfo {
    int     iLeft;
    int     iRight;
    int     iHeight;
};

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    int         i           = 0;
    int         j           = 0;
    int         iRow        = matrixSize;
    int         iCol        = matrixColSize[0];
    int         iCurLeft    = 0;
    int         iCurRight   = 0;
    int         iTmpS       = 0;
    int         iMaxS       = 0;
    struct PointInfo* pDP   = NULL;

    if((NULL == matrix) || (NULL == matrixColSize) || (0 == matrixSize)) return 0;

    //1,初始化动态规划数组
    pDP = (struct PointInfo*)malloc(sizeof(struct PointInfo) * (iCol + 1));
    memset(pDP, 0x00, sizeof(struct PointInfo) * (iCol + 1));
    for(j = 0; j <= iCol; j++)
    {
        pDP[j].iLeft = 0;
        pDP[j].iRight = iCol;
        pDP[j].iHeight = 0;
    }

    //2,遍历数组
    for(i = 1; i <= iRow; i++)
    {
        iCurLeft = 0;
        for(j = 1; j <= iCol; j++)
        {
            //3,计算高
            if(matrix[i - 1][j - 1] == '0')
            {
                pDP[j].iHeight = 0;
            }
            else
            {
                pDP[j].iHeight += 1;
            }

            //4,计算左边
            if(matrix[i - 1][j - 1] == '0')
            {
                pDP[j].iLeft = 0;
                iCurLeft = j;
            }
            else
            {
                pDP[j].iLeft = MAX_II(pDP[j].iLeft, iCurLeft);
            }
        }

        iCurRight = iCol;
        for(j = iCol; j > 0; j--)
        {
            //5,计算右边
            if(matrix[i - 1][j - 1] == '0')
            {
                pDP[j].iRight = iCol;
                iCurRight = j - 1;
            }
            else
            {
                pDP[j].iRight = MIN_II(pDP[j].iRight, iCurRight);
            }

            //6,计算面积，并找到最大面积
            iTmpS = (pDP[j].iRight - pDP[j].iLeft) * pDP[j].iHeight;
            iMaxS = MAX_II(iTmpS, iMaxS);
        }
    }

    //7,释放空间
    free(pDP);

    return iMaxS;
}



/*
//方法一：动态规划法
//1,建立 dp[iRow][iCol] 个元素为 (m, n) 数组, m、n为当前位置能够达到最大矩形的行、列
//2,dp[iRow][iCol]的 (m,n) 有两组值，一个是 (dp[iRow][iCol-1].m, dp[iRow-1][iCol-1].n + 1)
//  一个是 (dp[iRow-1][iCol].m+1, dp[iRow-1][iCol].n) 计算两组面积，哪个大用哪个
//3,优化后发现，只需要 dp[iCol] 就能够满足要求

#define     MAX_III(a, b, c)    ((a) > ((b) > (c) ? (b) : (c)) ? (a) : ((b) > (c) ? (b) : (c)))
#define     MAX_II(a, b)        ((a) > (b) ? (a) : (b))
#define     MIN_II(a, b)        ((a) < (b) ? (a) : (b))
int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    int         i           = 0;
    int         j           = 0;
    int         iRow        = matrixSize;
    int         iCol        = matrixColSize[0];
    int         iTmpS_R     = 0;
    int         iTmpS_C     = 0;
    int         iTmpS       = 0;
    int         iMaxS       = 0;
    int**       pDP         = 0;

    if((NULL == matrix) || (NULL == matrixColSize) || (0 == matrixSize)) return 0;

    //1,初始化动态规划数组
    pDP = (int**)malloc(sizeof(int*) * (iCol + 1));
    for(j = 0; j <= iCol; j++)
    {
        pDP[j] = (int*)malloc(sizeof(int) * 2);
        memset(pDP[j], 0x00, sizeof(int) * 2);
    }

    //2,遍历数组
    for(i = 1; i <= iRow; i++)
    {
        for(j = 1; j <= iCol; j++)
        {
            if(matrix[i - 1][j - 1] == '0')
            {
                //4,如果 matrix[i,j]==0,则 dp[j]=0
                pDP[j][0] = 0;
                pDP[j][1] = 0;
            }
            else
            {
                if(((pDP[j - 1][0] == 0) && (pDP[j - 1][1] == 0)) || 
                    ((pDP[j][0] == 0) && (pDP[j][1] == 0)))
                {
                    if((pDP[j - 1][0] == 0) && (pDP[j - 1][1] == 0))
                    {
                        //5,如果左边的坐标为(0, 0)
                        pDP[j][0] = pDP[j][0] + 1;
                        pDP[j][1] = 1;
                    }
                    if((pDP[j][0] == 0) && (pDP[j][1] == 0))
                    {
                        //6，如果下面一个坐标为(0, 0)
                        pDP[j][0] = 1;
                        pDP[j][1] = pDP[j - 1][1] + 1;
                    }

                    iTmpS = pDP[j][0] * pDP[j][1];
                    iMaxS = MAX_II(iMaxS, iTmpS);
                }
                else
                {

                    //7,当左边和右边都有值时，如何确定(m, n)
                    if((pDP[j-1][0] > pDP[j][0] + 1) && (pDP[j][1] > pDP[j - 1][1] + 1))
                    {
                        pDP[j][0] = pDP[j][0] + 1;
                        pDP[j][1] = pDP[j - 1][1] + 1;
                        
                        iTmpS = pDP[j][0] * pDP[j][1];
                        iMaxS = MAX_II(iMaxS, iTmpS);
                    }
                    else if(pDP[j-1][0] > pDP[j][0] + 1)
                    {
                        pDP[j][0] = pDP[j][0] + 1;
                        pDP[j][1] = pDP[j][1];

                        iTmpS = pDP[j][0] * pDP[j][1];
                        iMaxS = MAX_II(iMaxS, iTmpS);
                    }
                    else if(pDP[j][1] > pDP[j - 1][1] + 1)
                    {
                        pDP[j][1] = pDP[j - 1][1] + 1;
                        pDP[j][0] = pDP[j - 1][0];

                        iTmpS = pDP[j][0] * pDP[j][1];
                        iMaxS = MAX_II(iMaxS, iTmpS);
                    }
                    else
                    {
                        //7,求当前位置从左边计算的面积，和从下面计算的面积
                        iTmpS_R = (pDP[j - 1][0]) * (pDP[j - 1][1] + 1);
                        iTmpS_C = (pDP[j][0] + 1) * (pDP[j][1]);
                        if(iTmpS_R > iTmpS_C)
                        {
                            pDP[j][0] = pDP[j - 1][0];
                            pDP[j][1] = pDP[j - 1][1] + 1;
                        }
                        else
                        {
                            pDP[j][0] = pDP[j][0] + 1;
                            pDP[j][1] = pDP[j][1];
                        }

                        //8,计算最大面积
                        iMaxS = MAX_III(iMaxS, iTmpS_R, iTmpS_C);
                    }
                }


            }

            if(i > 5)
            printf("[1][i=%d][j=%d][val=%c][%d, %d]\n", i, j, matrix[i - 1][j - 1], pDP[j][0], pDP[j][1]);
        }
    }

    //9,释放空间
    for(j = 0; j <= iCol; j++)
    {
        free(pDP[j]);
    }
    free(pDP);

    return iMaxS;
}

*/
```