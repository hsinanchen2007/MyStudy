```
int goLeft(char** board, int x, int y)
{
    int res = 0;
    int i;
    if (y - 1 >= 0) {
        for (i = y - 1; i >= 0; i--) {
            if (board[x][i] == 'B') {
                res = 0;
                break;
            }
            if (board[x][i] == 'p') {
                res = 1;
                break;
            }
        }
    }

    return res;
}
int goRight(char** board, int x, int y)
{
    int res = 0;
    int i;
    if (y + 1 < 8) {
        for (i = y + 1; i < 8; i++) {
            if (board[x][i] == 'B') {
                res = 0;
                break;
            }
            if (board[x][i] == 'p') {
                res = 1;
                break;
            }
        }
    }
    return res;
}
int goUp(char** board, int x, int y)
{
    int res = 0;
    int i;
    if (x - 1 >= 0) {
        for (i = x - 1; i >= 0; i--) {
            if (board[i][y] == 'B') {
                res = 0;
                break;
            }
            if (board[i][y] == 'p') {
                res = 1;
                break;
            }
        }
    }
    return res;
}
int goDown(char** board, int x, int y)
{
    int res = 0;
    int i;
    if (x + 1 < 8) {
        for (i = x + 1; i < 8; i++) {
            if (board[i][y] == 'B') {
                res = 0;
                break;
            }
            if (board[i][y] == 'p') {
                res = 1;
                break;
            }
        }
    }
    return res;
}
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int row = boardSize;
    int col = boardColSize[0];
    int i, j;
    int res = 0;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (board[i][j] == 'R') {
                if (goLeft(board, i, j)) {
                    res++;
                }
                if (goRight(board, i, j)) {
                    res++;
                }
                if (goUp(board, i, j)) {
                    res++;
                }
                if (goDown(board, i, j)) {
                    res++;
                }
                return res;
            }
        }
    }
    return res;
}
```
