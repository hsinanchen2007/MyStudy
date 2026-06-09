### 解题思路
深度优先 回溯 东南西北

### 代码

```c
static bool dfs(char** board, int boardSize, int* boardColSize, char* word,
                bool** ppbUsed, int row, int col)
{
    if (*word == '\0')
    {
        return true;
    }

    if (row < 0 || row > (boardSize - 1) || col < 0 || col > (*boardColSize - 1))
    {
        return false;
    }

    if (ppbUsed[row][col] == true || board[row][col] != *word)
    {
        return false;
    }

    ppbUsed[row][col] = true;

    if (dfs(board, boardSize, boardColSize, word + 1, ppbUsed, row + 1, col))
    {
        return true; // N
    }

    if (dfs(board, boardSize, boardColSize, word + 1, ppbUsed, row - 1, col))
    {
        return true; // S
    }

    if (dfs(board, boardSize, boardColSize, word + 1, ppbUsed, row, col - 1))
    {
        return true; // W
    }

    if (dfs(board, boardSize, boardColSize, word + 1, ppbUsed, row, col + 1))
    {
        return true; // E
    }

    ppbUsed[row][col] = false;

    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    int row = 0;
    int col = 0;
    bool** ppbUsed = (bool**)malloc(boardSize * sizeof(bool*));
    for (row = 0; row <= boardSize - 1; row++)
    {
        ppbUsed[row] = (bool*)malloc(*boardColSize * sizeof(bool));
        memset(ppbUsed[row], false, *boardColSize);
    }

    for (row = 0; row <= boardSize - 1; row++)
    {
        for (col = 0; col <= *boardColSize - 1; col++)
        {
            if (dfs(board, boardSize, boardColSize, word, ppbUsed, row, col))
            {
                return true;
            }
        }
    }

    return false;
}

```