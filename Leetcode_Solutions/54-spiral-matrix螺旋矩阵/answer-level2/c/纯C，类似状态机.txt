### 解题思路
方法一：
设置一个锚点，循环遍历一次，每一步判定锚点的位置

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//方法一：
//设置一个锚点，循环遍历一次，每一步判定锚点的位置

#define     STEP_RIGHT      0
#define     STEP_DOWN       1
#define     STEP_LEFT       2
#define     STEP_UPPER      3
#define     INVALID         0xFFFF

struct TargetPoint{
    int     row;    //行
    int     col;    //列
    int     dir;    //方向
};

//函数一：判定锚点的下一个位置
void targetPointNext(int** matrix, int rowNum, int colNum, struct TargetPoint* pPoint){

//    printf("[1][row=%d][col=%d][dir=%d]\n", pPoint->row, pPoint->col, pPoint->dir);

    //1,将当前位置数组的值修改为无效值，防止重复
    matrix[pPoint->row][pPoint->col] = INVALID;

    //2,根据方向判定下一步的位置
    if (STEP_RIGHT == pPoint->dir)
    {
        //向右
        if (((pPoint->col + 1) >= colNum) || 
            (INVALID == matrix[pPoint->row][pPoint->col + 1]))
        {
            pPoint->dir = STEP_DOWN;
            pPoint->row += 1;
        }
        else
        {
            pPoint->col += 1;
        }
    }
    else if (STEP_DOWN == pPoint->dir)
    {
        //向下
        if (((pPoint->row + 1) >= rowNum) || 
            (INVALID == matrix[pPoint->row + 1][pPoint->col]))
        {
            pPoint->dir = STEP_LEFT;
            pPoint->col -= 1;
        }
        else
        {
            pPoint->row += 1;
        }
    }
    else if (STEP_LEFT == pPoint->dir)
    {
        //向左
        if (((pPoint->col - 1) < 0) || 
            (INVALID == matrix[pPoint->row][pPoint->col - 1]))
        {
            pPoint->dir = STEP_UPPER;
            pPoint->row -= 1;
        }
        else
        {
            pPoint->col -= 1;
        }
    }
    else
    {
        //向上
        if (((pPoint->row - 1) < 0) || 
            (INVALID == matrix[pPoint->row - 1][pPoint->col]))
        {
            pPoint->dir = STEP_RIGHT;
            pPoint->col += 1;
        }
        else
        {
            pPoint->row -= 1;
        }
    }
    return;
}

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int     i       = 0;
    int     iNum    = 0;
    int*    pRet    = NULL;
    struct TargetPoint  tPoint;

    if ((NULL == matrix) || (0 == matrixSize))
    {
        *returnSize = 0;
        return NULL;
    }

    //1,初始化
    iNum = matrixSize * (matrixColSize[0]);
    pRet = (int*)malloc(sizeof(int) * iNum);
    memset(pRet, 0x00, sizeof(int) * iNum);
    memset(&tPoint, 0x00, sizeof(struct TargetPoint));


    //2,循环处理
    for (i = 0; i < iNum; i++)
    {
        pRet[i] = matrix[tPoint.row][tPoint.col];

        targetPointNext(matrix, matrixSize, matrixColSize[0], &tPoint);
    }

    //3,返回
    *returnSize = iNum;
    return pRet;
}
```