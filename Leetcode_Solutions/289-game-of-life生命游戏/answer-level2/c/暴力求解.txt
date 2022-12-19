int CalLiveNodeNextSta(int aroundLiveNum)
{
    int ret;
    if ((aroundLiveNum < 2)) {
        ret = 0;
    } else if (aroundLiveNum == 2 || aroundLiveNum == 3) {
        ret = 1;      
    } else {
        ret = 0;
    }

    return ret;
}

int CalDeadNodeNextSta(int aroundLiveNum)
{
    int ret;
    if (aroundLiveNum == 3) {
        ret = 1;
    } else {
        ret = 0;
    }  
    return ret;
}

int LiveDieJudge(int** board, int x, int y, int livenumber)
{
    int ret;

    if (board[x][y] == 1) {
        ret = CalLiveNodeNextSta(livenumber);
    } else {
        ret = CalDeadNodeNextSta(livenumber);
    }

    return ret;
}

int LiveNumAround(int** board, int boardSize, int* boardColSize, int x, int y)
{
    if (x < 0 || y < 0 || x >= boardSize || y >= *boardColSize) {
        return 0;
    }

    return board[x][y];
}

int Calc(int** board, int boardSize, int* boardColSize, int x, int y)
{
    int row = x;
    int col = y;
    int liveNum;
    int liveOrDie;
  
    liveNum = LiveNumAround(board, boardSize, boardColSize, x, y - 1) +
        LiveNumAround(board, boardSize, boardColSize, x, y + 1) +
        LiveNumAround(board, boardSize, boardColSize, x - 1, y) + 
        LiveNumAround(board, boardSize, boardColSize, x + 1,y) +
        LiveNumAround(board, boardSize, boardColSize, x - 1,y - 1) +
        LiveNumAround(board, boardSize, boardColSize, x - 1,y + 1) +
        LiveNumAround(board, boardSize, boardColSize, x + 1,y - 1) +
        LiveNumAround(board, boardSize, boardColSize, x + 1,y + 1);

    liveOrDie = LiveDieJudge(board, x, y, liveNum);
    return liveOrDie;
}

void step(int** board, int boardSize, int* boardColSize, int **temp)
{
    int i;
    int j;
    for (i = 0; i < boardSize; i++) {
        temp[i] = (int *)malloc(sizeof(int) * (*boardColSize));
        memset(temp[i], 0, sizeof(int) * (*boardColSize));

        for (j = 0; j < *boardColSize; j++) {
            temp[i][j] = Calc(board, boardSize, boardColSize, i, j);
        }

    }

    for (i = 0; i < boardSize; i++) {
        memcpy(board[i], temp[i], sizeof(int) * (*boardColSize));
    }
}

void gameOfLife(int** board, int boardSize, int* boardColSize){
    if (board == NULL || boardSize == 0 || *boardColSize == 0) {
        return 0;
    }
    int **temp = (int **)malloc(sizeof(int *) * boardSize);
    if (temp == NULL) {
        return 0;
    }

    step (board, boardSize, boardColSize, temp);
    return board;
}