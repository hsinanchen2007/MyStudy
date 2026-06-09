### 解题思路
实在TM不想说话，看下面带fxxk的注释就懂了，能把returnColumnSizes解释的清楚点吗？
猜测这题打印的时候不是 col < (returncolumnSize)[i]， 而是col <= (returncolumnSize)[i] !

### 代码

```c
#define MAX 5000

const int dir[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
char ***g_ans;
int g_ansSize;

int **board;

bool check(int row, int col, int n) {
    int newRow, newCol;
    for (int i = 0; i < 8; ++i) {
        newRow = row + dir[i][0];
        newCol = col + dir[i][1];
        // Do check until out of board
        while(newRow >= 0 && newRow < n && newCol >=0 && newCol < n) {
            if (board[newRow][newCol] == 1) {
                return false;
            }
            newRow = newRow + dir[i][0];
            newCol = newCol + dir[i][1];
        }
        
    }
    return true;
}

void genResult(int n) {
    g_ans[g_ansSize] = malloc(sizeof(char *) * n);
    for (int i = 0; i < n; ++i) {
        g_ans[g_ansSize][i] = malloc(sizeof(char) * (n + 1)); // one more char for '\0' ??? fuck leetcode
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 1) {
                g_ans[g_ansSize][i][j] = 'Q';
            } else {
                g_ans[g_ansSize][i][j] = '.';
            }
        }
        g_ans[g_ansSize][i][n] = '\0';
    }
    ++g_ansSize;
}

void dump(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void dfs(int n, int pos) {
    if (pos == n) {
        //dump(n);
        genResult(n);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (check(pos, i, n)) {
            board[pos][i] = 1;
            dfs(n, pos + 1);
            board[pos][i] = 0;  // backtrack
        }
    }
}

void initBoard(int n) {
    board = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; ++i) {
        board[i] = malloc(sizeof(int) * n);
        memset(board[i], 0, sizeof(int) * n);
    }
}

void freeBoard(int n) {
    for (int i = 0; i < n; ++i) {
        free(board[i]);
    }
    free(board);
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    initBoard(n);
    g_ans = (char ***)malloc(sizeof(char *) * MAX);
    g_ansSize = 0;
    dfs(n, 0);
    *returnSize = g_ansSize;
    *returnColumnSizes = (int *)malloc(sizeof(int) * g_ansSize);
    for (int i = 0; i < g_ansSize; ++i) {
        (*returnColumnSizes)[i] = n;
    }
    freeBoard(n);
    return g_ans;
}
```