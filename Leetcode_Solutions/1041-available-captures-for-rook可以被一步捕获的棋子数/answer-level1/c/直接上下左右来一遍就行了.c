### 解题思路
直接上下左右来一遍就行了

### 代码

```c
int dfs(char** board, int boardSize, int* boardColSize, int xR, int yR, int x, int y)
{
    if (xR + x < 0 || xR + x >= boardSize || yR + y < 0 || yR + y >= boardColSize[xR + x]) {
        return 0;
    }
    if (board[xR + x][yR + y] == 'B') {
        return 0;
    } else if (board[xR + x][yR + y] == 'p') {
        return 1;
    } else {
        return dfs(board, boardSize, boardColSize, xR + x, yR + y, x, y);
    }
}
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int xR;
    int yR;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == 'R') {
                xR = i;
                yR = j;
                break;
            }
        }
    }
    int left = dfs(board, boardSize, boardColSize, xR, yR, 1, 0);
    int right = dfs(board, boardSize, boardColSize, xR, yR, -1, 0);
    int up = dfs(board, boardSize, boardColSize, xR, yR, 0, 1);
    int down = dfs(board, boardSize, boardColSize, xR, yR, 0, -1);
    return left + right + up + down;
}
```