```c
char ***g_solves;
int g_solveCnt;
/* 棋盘上0表示空格，-1表示QUEEN，数字表示被第几个QUEEN占用，用来方便的trackback */
int g_board[15][15];
int g_num[] = {
    1,
    0,
    0,
    2,
    10,
    4,
    40,
    92,
    352,
    724,
    2680,
    14200,
    73712,
    365596,
    2279184
};

/* 水平垂直和对角的8个方向 */
int g_direction[8][2] = {
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1},
    {-1, -1},
    {-1, 0},
    {-1, 1}
};

/* 获取一个新的棋谱 */
char **GetOneEmptyBoard(int n) {
    char **chessBoard = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        chessBoard[i] = (char *)malloc((n + 1) * sizeof(char));
        memset(chessBoard[i], 0, (n + 1) * sizeof(char));
    }
    return chessBoard;
}

/* 将棋谱保存起来 */
void OutputOneResult(int n) {
    char **board = GetOneEmptyBoard(n);

    for (int i = 0; i < n; i++) {
        char *row = board[i];
        for (int j = 0; j < n; j++) {
            if (g_board[i][j] == -1) {
                row[j] = 'Q';
            } else {
                row[j] = '.';
            }
        }
    }

    g_solves[g_solveCnt++] = board;
    return;
}

/* 放置QUEEN，并在水平垂直对角放置占位符 */
void PlaceQueen(int n, int x, int y) {
    g_board[x][y] = -1;
    
    for (int i = 0; i < 8; i++) {
        int *dir = &g_direction[i][0];
        int nx = x;
        int ny = y;
        while (true) {
            nx += dir[0];
            ny += dir[1];
            if ((nx < 0) || (nx >= n) || (ny < 0) || (ny >= n)) {
                break;
            }
            /* 由于是逐行扫描，因此这里保存行号。行号从1开始，因为0已经用来表示空格 */
            if (g_board[nx][ny] == 0) {
                g_board[nx][ny] = x + 1;
            }
        }
    }

    return;
}

/* 回溯，需要移除放置的QUEEN，以及占用的格子，直接扫描整个棋盘，把等于x+1的格子释放即可 */
void RemoveQueen(int n, int x, int y) {
    g_board[x][y] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g_board[i][j] == (x + 1)) {
                g_board[i][j] = 0;
            }
        }
    }
    return;
}

/* 回溯法，通过函数封装，整理为经典的代码结构
    1、判断是否为解，是则输出解
    2、不是解，本层放置QUEEN，进入递归进入下一层
    3、本层解已经求完解，递归函数return，回溯到上一层，到下一个合适的位置摆放
    4、全部完成求解，输出 */
void BackTrack(int n, int index)
{
    if (index >= n) {
        OutputOneResult(n);
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (g_board[index][i] != 0) {
            continue;
        }

        PlaceQueen(n, index, i);
        BackTrack(n, index + 1);
        RemoveQueen(n, index, i);
    }
    return;
}

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    g_solves = (char ***)malloc(g_num[n - 1] * sizeof(char **));
    g_solveCnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g_board[i][j] = 0;
        }
    }
    BackTrack(n, 0);

    *returnSize = g_solveCnt;

    int *col = (int *)malloc(g_solveCnt * sizeof(int));
    for (int i = 0; i < g_solveCnt; i++) {
        col[i] = n;
    }
    *returnColumnSizes = col;
    return g_solves;
}
```