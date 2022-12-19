### 解题思路
方法一：
1，将该题分解为：给定坐标[i,j],在二维网格中是否能够匹配单词,在二维网格中所有匹配第一个字母的位置匹配一次单词
2，如何在二维网格中匹配一个单词，回溯法
### 代码

```c

//方法一：
//1，将该题分解为：给定坐标[i,j],在二维网格中是否能够匹配单词,在二维网格中所有匹配第一个字母的位置匹配一次单词
//2，如何在二维网格中匹配一个单词，回溯法

//函数一：回溯法匹配单词
bool backTrackExist(char** board, int iRowSize, int iColSize, int iRow, int iCol, char* word, char** pBFlag, int iStep)
{
    bool    bMatch      = false;
    int     iWordLen    = strlen(word);

    //1,结束条件
    if(iStep == iWordLen - 1)
    {
        return true;
    }

    //2,判定下一步是否有匹配单词
    pBFlag[iRow][iCol] = 1;
    if ((iRow - 1 >= 0) && (pBFlag[iRow - 1][iCol] == 0) && (board[iRow - 1][iCol] == word[iStep + 1]))
    {
        //上匹配
        bMatch = backTrackExist(board, iRowSize, iColSize, iRow - 1, iCol, word, pBFlag, iStep + 1);
        if(bMatch) return bMatch;
    }
    if ((iCol + 1 < iColSize) && (pBFlag[iRow][iCol + 1] == 0) && (board[iRow][iCol + 1] == word[iStep + 1]))
    {
        //右匹配
        bMatch = backTrackExist(board, iRowSize, iColSize, iRow, iCol + 1, word, pBFlag, iStep + 1);
        if(bMatch) return bMatch;
    }
    if ((iRow + 1 < iRowSize) && (pBFlag[iRow + 1][iCol] == 0) && (board[iRow + 1][iCol] == word[iStep + 1]))
    {
        //下匹配
        bMatch = backTrackExist(board, iRowSize, iColSize, iRow + 1, iCol, word, pBFlag, iStep + 1);
        if(bMatch) return bMatch;
    }
    if ((iCol - 1 >= 0) && (pBFlag[iRow][iCol - 1] == 0) && (board[iRow][iCol - 1] == word[iStep + 1]))
    {
        //左匹配
        bMatch = backTrackExist(board, iRowSize, iColSize, iRow, iCol - 1, word, pBFlag, iStep + 1);
        if(bMatch) return bMatch;
    }

    //3,回溯处理
    pBFlag[iRow][iCol] = 0;
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    int     i           = 0;
    int     j           = 0;
    int     k           = 0;
    int     iRow        = boardSize;
    int     iCol        = boardColSize[0];
    bool    bRet        = false;
    char**  pBoardFlag  = NULL;

    if((NULL == board) || (NULL == word)) return false;

    //1,初始化二维网格匹配标记数组
    pBoardFlag = (char**)malloc(sizeof(char*) * iRow);
    for(i = 0; i < iRow; i++)
    {
        pBoardFlag[i] = (char*)malloc(sizeof(char) * iCol);
    }

    //2,循环二维网格，寻找坐标，进行匹配单词
    for(i = 0; i < iRow; i++)
    {
        for(j = 0; j < iCol; j++)
        {
            if (board[i][j] == word[0])
            {
                for(k = 0; k < iRow; k++)
                {
                    memset(pBoardFlag[k], 0x00, sizeof(char) * iCol);
                }

                //3,给定坐标[i,j],匹配单词
                bRet = backTrackExist(board, iRow, iCol, i, j, word, pBoardFlag, 0);
                if (bRet) return bRet;
            }
        }
    }

    //4,释放空间
    for(k = 0; k < iRow; k++)
    {
        free(pBoardFlag[k]);
    }
    free(pBoardFlag);

    return bRet;
}

/*
//函数二：给定坐标[i, j],判定是否能够匹配单词
bool fixPointExist(char** board, int iRowSize, int iColSize, int iRow, int iCol, char* word){
    int         i               = 0;
    bool        bRet            = false;
    char**      pBoardFlag      = NULL;

    pBoardFlag = (char**)malloc(sizeof(char*) * iRowSize);
    for(i = 0; i < iRowSize; i++)
    {
        pBoardFlag[i] = (char*)malloc(sizeof(char) * iColSize);
        memset(pBoardFlag[i], 0x00, sizeof(char) * iColSize);
    }

    //回溯调用
    bRet = backTrackExist(board, iRowSize, iColSize, iRow, iCol, word, pBoardFlag, 0);

    for(i = 0; i < iRowSize; i++)
    {
        free(pBoardFlag[i]);
    }
    free(pBoardFlag);

    return bRet;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    int     i           = 0;
    int     j           = 0;
    int     iRow        = boardSize;
    int     iCol        = boardColSize[0];
    bool    bRet        = false;

    if((NULL == board) || (NULL == word)) return false;

    for(i = 0; i < iRow; i++)
    {
        for(j = 0; j < iCol; j++)
        {
            if (board[i][j] == word[0])
            {
                bRet = fixPointExist(board, iRow, iCol, i, j, word);
                if (bRet) return bRet;
            }
        }
    }
    return bRet;
}
*/
```