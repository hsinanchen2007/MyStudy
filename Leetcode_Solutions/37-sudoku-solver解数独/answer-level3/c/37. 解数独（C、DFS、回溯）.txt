### 解题思路
从0，0开始，如果已经有数字，就继续看周围的格子。如果没有数字，就在同行、同列、同九宫格中遍历获取未使用的数字，挨个尝试直到成功。如果都不成功，则恢复当前格，回溯上一步。

### 代码

```c
#define NUM_CNT 9

typedef struct tagPOS_S{
    int x;
    int y;
}POS_S;

void GetValidNum(char **board, int boardSize, POS_S *pos, char validNums[NUM_CNT + 1])
{
    int i;
    for (i = 0; i < NUM_CNT; i++) {
        int val = board[pos->x][i];
        if (val != '.') {
            validNums[val - '0'] = 1;
        }
    }
    for (i = 0; i < NUM_CNT; i++) {
        int val = board[i][pos->y];
        if (val != '.') {
            validNums[val - '0'] = 1;
        }
    }

    int j;
    for (i = pos->x / 3 * 3; i < (pos->x / 3 + 1) * 3; i++) {
        for (j = pos->y /3 * 3; j < (pos->y / 3 + 1) * 3; j++){
            int val = board[i][j];
            if (val != '.') {
                validNums[val - '0'] = 1;
            }
        }
    }

    return;
}
bool dfs(char **board, int boardSize, POS_S *curPos, char *boardMap);
bool dfsAround(char **board, int boardSize, POS_S *curPos, char *boardMap) {
    int i;
    int dd[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    for (i = 0; i < 4; i++) {
        int nextX = curPos->x + dd[i][0];
        int nextY = curPos->y + dd[i][1];
        if (0 <= nextX && nextX < NUM_CNT && 0 <= nextY && nextY < NUM_CNT) {
            POS_S nextPos = {nextX, nextY};
            bool ret = dfs(board, boardSize, &nextPos, boardMap);
            if (ret == false) {
                return false;
            }
        }
    }
    return true;       
}

bool dfs(char **board, int boardSize, POS_S *curPos, char *boardMap)
{
    int i;

    /* 去重 */
    if (boardMap[curPos->x * boardSize + curPos->y] == 1) {
        return true;
    }
    boardMap[curPos->x * boardSize + curPos->y] = 1;

    /* 当前位置已有数字，检查周围的位置 */
    if (board[curPos->x][curPos->y] != '.') {
        bool ret = dfsAround(board, boardSize, curPos, boardMap);
        /* 如果检查结果错误，则返回错误。回溯到上个节点时，尝试其他数字。 */
        if (ret == false) {
            /* 已查标记清一下 */
            boardMap[curPos->x * boardSize + curPos->y] = 0;
        }
        return ret;
    }

    /* 遍历可选数字，挨个尝试，直到成功 */
    char numMap[NUM_CNT + 1] = {0};
    GetValidNum(board, boardSize, curPos, numMap);
    for (i = 1; i <= NUM_CNT; i++) {
        if (numMap[i] == 1) {
            continue;
        }
        board[curPos->x][curPos->y] = i + '0';

        bool ret = dfsAround(board, boardSize, curPos, boardMap);
        if (ret == true) {
            return true;
        }
    }
    
    /*如果试过所有数字都不行，则还原本格数字，继续回溯*/
    board[curPos->x][curPos->y] = '.';
    boardMap[curPos->x * boardSize + curPos->y] = 0;
    return false;
}



void solveSudoku(char** board, int boardSize, int* boardColSize){
    if (board == NULL || boardColSize == NULL) {
        return;
    }

    char *boardMap = (char *)malloc(boardSize * boardSize);
    if (boardMap == NULL) {
        return;
    }
    memset(boardMap, 0, boardSize * boardSize);
    POS_S pos = {0, 0};
    dfs(board, boardSize, &pos, boardMap);

    return;    
}
```