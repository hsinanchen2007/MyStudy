### 解题思路
此处撰写解题思路

### 代码

```c
void dfs(char** board, int boardSize, int* boardColSize, int row, int col) {
    if (row < 0 || row > boardSize -1 || col < 0 || col > boardColSize[0] - 1 || board[row][col] != 'O') {
        return;
    }

    /* 标记为不可替换 */
    board[row][col] = 'U';

    dfs(board, boardSize, boardColSize, row + 1, col);
    dfs(board, boardSize, boardColSize, row - 1, col);
    dfs(board, boardSize, boardColSize, row, col - 1);
    dfs(board, boardSize, boardColSize, row, col + 1);
}

void solve(char** board, int boardSize, int* boardColSize){
    int i, j;
    if (board == NULL || boardSize < 1 || boardColSize[0] < 1) {
        return;
    }

    /* 上下边界 */
    for (i = 0; i < boardColSize[0]; i++) {
        dfs(board, boardSize, boardColSize, 0, i);
        dfs(board, boardSize, boardColSize, boardSize - 1, i);
    }

    /* 左右边界 */
    for (i = 1; i < boardSize - 1; i++) {
        dfs(board, boardSize, boardColSize, i, 0);
        dfs(board, boardSize, boardColSize, i, boardColSize[0] - 1);
    }

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize[0]; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == 'U') {
                board[i][j] = 'O';
            }
        }
    }
}
```