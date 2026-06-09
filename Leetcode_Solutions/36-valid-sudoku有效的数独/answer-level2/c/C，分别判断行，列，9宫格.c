### 解题思路
方法一：分三步分析输入数独是否有效
1，循环判断行是否都有效
2，循环判断列是否都有效
3，循环判断每个9宫格是否都有效
三者都有效时整个数独才有效

### 代码

```c
//方法一：分三步分析输入数独是否有效
//1，循环判断行是否都有效
//2，循环判断列是否都有效
//3，循环判断每个9宫格是否都有效
//三者都有效时整个数独才有效
bool isValidLine(char** board, int line){
    int     iNumFlag[9]     = {0};
    int     index           = 0;
    bool    bRet            = true;

    for (index = 0; index < 9; index++)
    {
        if ((board[line][index] >= '1') && (board[line][index] <= '9'))
        {
            if (1 == iNumFlag[board[line][index] - '1'])
            {
                bRet = false;
                return bRet;
            }
            else
            {
                iNumFlag[board[line][index] - '1'] = 1;
            }
        }
    }
    return bRet;
}

bool isValidColumn(char** board, int column){
    int     iNumFlag[9]     = {0};
    int     index           = 0;
    bool    bRet            = true;

    for (index = 0; index < 9; index++)
    {
        if ((board[index][column] >= '1') && (board[index][column] <= '9'))
        {
            if (1 == iNumFlag[board[index][column] - '1'])
            {
                bRet = false;
                return bRet;
            }
            else
            {
                iNumFlag[board[index][column] - '1'] = 1;
            }
        }
    }
    return bRet;
}

bool isvalidSpace(char** board, int line, int column){
    int     iNumFlag[9]     = {0};
    int     i               = 0;
    int     j               = 0;
    bool    bRet            = true;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if ((board[line + i][column + j] >= '1') && (board[line + i][column + j] <= '9'))
            {
                if (1 == iNumFlag[board[line + i][column + j] - '1'])
                {
                    bRet = false;
                    return bRet;
                }
                else
                {
                    iNumFlag[board[line + i][column + j] - '1'] = 1;
                }
            }
        }
    }
    return bRet;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int     i       = 0;
    int     j       = 0;
    bool    bRet    = true;

    //行判断
    for (i = 0; i < 9; i++)
    {
        if (false == isValidLine(board, i))
        {
            bRet = false;
            return bRet;
        }
    }

    //列判断
    for (j = 0; j < 9; j++)
    {
        if (false == isValidColumn(board, j))
        {
            bRet = false;
            return bRet;
        }
    }

    //9宫格判断
    for (i = 0; i < 9; i += 3)
    {
        for (j = 0; j < 9; j += 3)
        {
            if (false == isvalidSpace(board, i, j))
            {
                bRet = false;
                return bRet;
            }
        }
    }
    return bRet;
}
```