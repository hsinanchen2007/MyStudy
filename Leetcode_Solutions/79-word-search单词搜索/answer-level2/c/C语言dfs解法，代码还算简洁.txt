
### 代码

```c
bool _exist(char **board, int row, int col, char *word, int y, int x)
{
    if (*word == '\0')
        return true;
    if (y < 0 || y >= row || x < 0 || x >= col || *word != board[y][x])
        return false;
    board[y][x] = '\0';
    bool result = _exist(board, row, col, word + 1, y, x - 1) ||
                  _exist(board, row, col, word + 1, y - 1, x) ||
                  _exist(board, row, col, word + 1, y, x + 1) ||
                  _exist(board, row, col, word + 1, y + 1, x);
    board[y][x] = *word;
    return result;
}
bool exist(char **board, int boardSize, int *boardColSize, char *word)
{
    for (int y = 0; y < boardSize; y++)
        for (int x = 0; x < boardColSize[0]; x++)
            if (board[y][x] == word[0] && _exist(board, boardSize, boardColSize[0], word, y, x))
                return true;
    return false;
}
```