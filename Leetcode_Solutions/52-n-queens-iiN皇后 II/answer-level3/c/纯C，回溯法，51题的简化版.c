### 解题思路
//方法一：回溯法
//1,边界，n个皇后放完了
//2,判定一个皇后是否能够放下的条件：行，列，正反斜线都不能有其他的皇后存在
//3,回溯标志，行数，也是皇后数量，每行肯定有一个皇后
//4,如何快速判断 行，列，正反斜线 是否有其他的皇后

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//方法一：回溯法
//1,边界，n个皇后放完了
//2,判定一个皇后是否能够放下的条件：行，列，正反斜线都不能有其他的皇后存在
//3,回溯标志，行数，也是皇后数量，每行肯定有一个皇后
//4,如何快速判断 行，列，正反斜线 是否有其他的皇后

#define     MIN(a, b)   (((a) < (b)) ? (a) : (b))
#define     MAX(a, b)   (((a) > (b)) ? (a) : (b))

//函数一：判断当前位置 row,col 是否能够放皇后
bool judgeQueenValid(char** pRet, int n, int row, int col){
    bool        bRet        = true;
    int         i           = 0;
    int         j           = 0;

    //1,行、列判断
    for (i = 0; i < n; i++)
    {
        if ((pRet[row][i] == 'Q') || (pRet[i][col] == 'Q'))
        {
            bRet = false;
            return bRet;
        }
    }

    //2,正斜线判断
    for (i = MAX(row - col, 0), j = MAX(col - row, 0); ((i < n) && (j < n)); i++, j++)
    {
        if (pRet[i][j] == 'Q')
        {
            bRet = false;
            return bRet;
        }
    }

    //3,反斜线判断
    for (i =MIN(row + col, n - 1), j = MAX(0, row + col - n + 1); ((i >= 0) && (j < n)); i--, j++)
    {
        if (pRet[i][j] == 'Q')
        {
            bRet = false;
            return bRet;
        }
    }

    return bRet;
}

//函数三：回溯处理
bool backTrackQueen(char** pRet, int n, int* returnSize, int row){
    int         i       = 0;
    int         j       = 0;
    bool        bValid  = false;

    //1,边界处理
    if (row == n)
    {
        // 成功找到一个答案
        *returnSize += 1;
        return true;
    }

    //2,回溯处理
    for (i = row; i < n; i++)
    {
        bValid = false;
        for (j = 0; j < n; j++)
        {
            //判断当前位置是否能够放皇后
            if (judgeQueenValid(pRet, n, i, j))
            {
                bValid = true;
                pRet[i][j] = 'Q';

                backTrackQueen(pRet, n, returnSize, i + 1);

                //3，回退处理
                bValid = false;
                pRet[i][j] = '.';
            }
        }

        //4,任何一行如果放不下皇后，则该条路不成立，返回上一层
        if (!bValid)
        {
            return false;
        }
    }
    return false;
}

int totalNQueens(int n){
    int             i           = 0;
    int             j           = 0;
    char**          pRet        = NULL;
    int             iRetSize    = 0;

    //1,初始化
    pRet = (char**)malloc(sizeof(char*) * n);
    memset(pRet, 0x00, sizeof(char*) * n);

    for (i = 0; i < n; i++)
    {
        pRet[i] = (char*)malloc(sizeof(char) * (n + 1)); 
        for (j = 0; j < n; j++)
        {
           pRet[i][j] = '.';
        }
        pRet[i][j] = '\0';
    }

    //2,回溯函数
    backTrackQueen(pRet, n, &iRetSize, 0);

    //3,返回
    return iRetSize;
}
```