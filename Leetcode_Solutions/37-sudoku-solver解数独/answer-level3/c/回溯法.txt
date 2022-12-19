### 解题思路

1. 分区索引
2. row, col, block 3个排斥数组
3. 回溯

### 代码

```c
int row[9][10];
int col[9][10];
int block[9][10];
bool solved = false;

void backtracking(char **board, int m, int n)
{
    int i;
    if (n == 9) {
        n = 0;
        m++;
    }
    if (m >= 9) {
        solved = true;
        return;
    }

    if (board[m][n] != '.') {
        backtracking(board, m, n + 1);
        return;
    }
    for (i = 1; i < 10; i++) {
        if (row[m][i] || col[n][i] || block[(m/3)*3+(n/3)][i]) continue;
        board[m][n] = i + '0';
        row[m][i] = 1;
        col[n][i] = 1;
        block[(m/3)*3+(n/3)][i] = 1;
        backtracking(board, m, n + 1);
        if (solved) return;
        board[m][n] = '.';
        row[m][i] = 0;
        col[n][i] = 0;
        block[(m/3)*3+(n/3)][i] = 0;
    }
}

void solveSudoku(char** board, int boardSize, int* boardColSize){
    int i;
    int j;
    solved = false;
    memset(row, 0, sizeof(int *) * 9);
    memset(col, 0, sizeof(int *) * 9);
    memset(block, 0, sizeof(int *) * 9);
    for (i = 0; i < 9; i++) {
        memset(row[i], 0, sizeof(int) * 10);
        memset(col[i], 0, sizeof(int )* 10);
        memset(block[i], 0, sizeof(int) * 10);
    }

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                row[i][board[i][j] - '0'] = 1;
                col[j][board[i][j] - '0'] = 1;
                block[(i/3)*3+(j/3)][board[i][j] - '0'] = 1;
            }
        }
    }
    backtracking(board, 0, 0);
}
```