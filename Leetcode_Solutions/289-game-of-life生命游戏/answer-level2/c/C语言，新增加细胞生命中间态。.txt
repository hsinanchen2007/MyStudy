思路：
    利用-1和-2标记中间状态，中间状态包含两个信息：细胞的原始状态和将要刷新后的状态。这样在处理其相邻的细胞状态时，既可以知道该细胞的原始状态，也可以知道最终该细胞状态应该是什么。在第二次遍历时将所有处于中间状态的细胞状态设置成其最终态。

代码：
#define LIVE        1
#define DEAD        0
#define LIVETODEAD  -1
#define DEADTOLIVE  -2

#define MAXDIR      8

bool IsLive(int **board, int boardSize, int *boardColSize, int row, int column)
{
    if (row < 0 || row >= boardSize || column < 0 || column >= boardColSize[row]) {
        return false;
    }

    if (*(*(board + row) + column) == LIVE ||
        *(*(board + row) + column) == LIVETODEAD) {
            return true;
        }

    return false;
}

/* 给定一个位置，返回其周围八个相邻位置活细胞的数量 */
int GetLiveCnt(int **board, int boardSize, int *boardColSize, int row, int column)
{
    int liveCnt = 0;
    /* 二维数组用于计算[row, column]周围八个方向的坐标 */
    int dir[MAXDIR][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    int i;

    for (i = 0; i < MAXDIR; i++) {
        if (IsLive(board, boardSize, boardColSize, row + dir[i][0], column + dir[i][1])) {
            liveCnt++;
        }
    }

    return liveCnt;
}

void gameOfLife(int** board, int boardSize, int* boardColSize){
    int i, j;
    int liveCnt;

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize[i]; j++) {
            liveCnt = GetLiveCnt(board, boardSize, boardColSize, i, j);
            if (*(*(board + i) + j) == LIVE) {
                if (liveCnt < 2 || liveCnt > 3) {
                    *(*(board + i) + j) = LIVETODEAD;
                }
            } else {
                if (liveCnt == 3) {
                    *(*(board + i) + j) = DEADTOLIVE;
                }
            }
        }
    }

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize[i]; j++) {
            if (*(*(board + i) + j) == LIVETODEAD) {
                *(*(board + i) + j) = DEAD;
            } else if (*(*(board + i) + j) == DEADTOLIVE) {
                *(*(board + i) + j) = LIVE;
            }
        }
    }

    return;    
}
