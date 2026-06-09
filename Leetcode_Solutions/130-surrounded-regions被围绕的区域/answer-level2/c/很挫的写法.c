### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX_VIST_LEN 200
int g_vist[MAX_VIST_LEN][MAX_VIST_LEN];
int g_reslt[MAX_VIST_LEN][MAX_VIST_LEN];
int g_isIn;

void findFitWord(int row, int col, char** board, int boardSize, int boardColSize)
{
    if (row < 0 || col < 0 || row >= boardSize || col >= boardColSize) {
        return;
    }
    
    if (g_vist[row][col] == 1) {
        return;
    }

    g_vist[row][col] = 1;

    if (board[row][col] == 'X') {
        return;
    }

    if (row == (boardSize -1) || col == (boardColSize - 1) || row == 0 || col == 0) {
        g_isIn = 0;
        return; 
    }

    g_reslt[row][col] = 1;

    findFitWord(row -1, col, board, boardSize, boardColSize);
    findFitWord(row, col - 1, board, boardSize, boardColSize);
    findFitWord(row + 1, col, board, boardSize, boardColSize);
    findFitWord(row, col + 1, board, boardSize, boardColSize);

    return;
}

void initData()
{
    g_isIn = 1;

    for (int i = 0; i < MAX_VIST_LEN; i++) {
        for (int j = 0; j < MAX_VIST_LEN; j++) {
            g_reslt[i][j] = 0;
            g_vist[i][j] = 0;
        }
    }

    return;
}

void fillData(char** board, int boardSize, int boardColSize)
{
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            if (g_reslt[i][j] == 1) {
                board[i][j] = 'X';
            }
        }
    }

    return;
}


void solve(char** board, int boardSize, int* boardColSize){
    if (board == NULL || boardSize == 0) {
        return;
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            if (board[i][j] == 'X') {
                continue;
            }

            initData();
            findFitWord(i, j, board, boardSize, boardColSize[0]);
            if (g_isIn == 1) {
                fillData(board, boardSize, boardColSize[0]);
            }
        }
    }

    return;
}
```