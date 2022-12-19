### 解题思路
标准dfs递归思路

### 代码

```c
void dfs(char** board, int i, int j, int boardSize, int colSize) {
    if (i < 0 || j < 0 || i >= boardSize || j >= colSize ||
        board[i][j] != 'O') {
        return;
    }

    board[i][j] = '#';
    dfs(board, i+1, j, boardSize, colSize);
    dfs(board, i, j+1, boardSize, colSize);
    dfs(board, i-1, j, boardSize, colSize);
    dfs(board, i, j-1, boardSize, colSize);
}

void solve(char** board, int boardSize, int* boardColSize){
    if (boardSize == 0 || boardColSize[0] == 0) {
        return;
    }

    int colSize = boardColSize[0];
    for (int i = 0; i < boardSize; i++) {
        if (board[i][0] == 'O') {
            dfs(board, i, 0, boardSize, colSize);
        }
        if(board[i][colSize - 1] == 'O') {
            dfs(board, i, colSize-1, boardSize, colSize);
        }
    }

    for (int j = 0; j < colSize; j++) {
        if (board[0][j] == 'O') {
            dfs(board, 0, j, boardSize, colSize);
        }
        if(board[boardSize - 1][j] == 'O') {
            dfs(board, boardSize - 1, j, boardSize, colSize);
        }
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (board[i][j] == '#') {
                board[i][j] = 'O';
            } else if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }

}
```