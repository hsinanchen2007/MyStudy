### 解题思路
1、从[i][j]的位置，分上下左右进行遍历；
2、注意，遇到第一个兵或者己方的棋子，循环退出；

### 代码

```c
int dfs(char **grid, int m, int n, int gridSize, int *gridColSize)
{
    int i, j;
    int count = 0;

    // 上
    for (i = m-1; i >= 0; i--) {
        if (grid[i][n] == 'B') {
            break;
        }

        if (grid[i][n] == 'p') {
            count++;
            break;
        }
    }

    // 下
    for (i = m+1; i < gridSize; i++) {
        if (grid[i][n] == 'B') {
            break;
        }

        if (grid[i][n] == 'p') {
            count++;
            break;
        }
    }

    // 左
    for (j = n-1; j >= 0; j--) {
        if (grid[m][j] == 'B') {
            break;
        }

        if (grid[m][j] == 'p') { 
            count++;
            break;
        }
    } 

     // 右
    for (j = n+1; j < gridColSize[0]; j++) {
        if (grid[m][j] == 'B') {
            break;
        }

        if (grid[m][j] == 'p') {
            count++;
            break;
        }
    } 

    return count;
}

int numRookCaptures(char** board, int boardSize, int* boardColSize)
{
    int i, j;
    int count = 0;

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize[0]; j++) {
            if (board[i][j] == 'R') {
                count = dfs(board, i, j, boardSize, boardColSize);
            }
        }
    }

    return count;
}
```