### 解题思路
方法一：参见例54螺旋矩阵

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//方法一：参见例54螺旋矩阵

#define     STEP_RIGHT      0       //向右
#define     STEP_DOWN       1       //向下
#define     STEP_LEFT       2       //向左
#define     STEP_UPPER      3       //向上

struct matrixPos {
    int     row;    //行
    int     col;    //列
    int     step;   //方向
};

//判定下一个位置
void judgeNextPos(int** pRet, int n, struct matrixPos* pPos){
    if (pPos->step == STEP_RIGHT)
    {
        if ((pPos->col + 1 < n) && (pRet[pPos->row][pPos->col + 1] == 0))
        {
            pPos->col += 1;
        }
        else
        {
            pPos->row += 1;
            pPos->step = STEP_DOWN;
        }
    }
    else if (pPos->step == STEP_DOWN)
    {
        if ((pPos->row + 1 < n) && (pRet[pPos->row + 1][pPos->col] == 0))
        {
            pPos->row += 1;
        }
        else
        {
            pPos->col -= 1;
            pPos->step = STEP_LEFT;
        }
    }
    else if (pPos->step == STEP_LEFT)
    {
        if ((pPos->col - 1 >= 0) && (pRet[pPos->row][pPos->col - 1] == 0))
        {
            pPos->col -= 1;
        }
        else
        {
            pPos->row -= 1;
            pPos->step = STEP_UPPER;
        }
    }
    else
    {
        if ((pPos->row - 1 >= 0) && (pRet[pPos->row - 1][pPos->col] == 0))
        {
            pPos->row -= 1;
        }
        else
        {
            pPos->col += 1;
            pPos->step = STEP_RIGHT;
        }
    }
    return;
}

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int         i       = 0;
    int**       pRet    = NULL;
    int*        pCol    = NULL;
    struct matrixPos    sPos;

    //1,初始化
    memset(&sPos, 0x00, sizeof(struct matrixPos));
    pRet = (int**)malloc(sizeof(int*) * n);
    pCol = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        pRet[i] = (int*)malloc(sizeof(int) * n);
        memset(pRet[i], 0x00, sizeof(int) * n);
        pCol[i] = n;
    }

    //2,循环填充返回数组
    for (i = 1; i <= n * n; i++)
    {
//        printf("[1][Ret[%d][%d]=%d]\n", sPos.row, sPos.col, i);
        pRet[sPos.row][sPos.col] = i;
        judgeNextPos(pRet, n, &sPos);
    }

    //3,返回
    *returnSize = n;
    *returnColumnSizes = pCol;
    return pRet;
}



```