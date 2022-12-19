```c
static inline int getPawn(const int i, const int j, char** board, int row, int col) {
    int l, k;
    int cnt = 0;
    for (l = i + 1; l < row; ++l) {
        if (board[l][j] == 'B' || board[l][j] == 'R') {
            break;
        }

        if (board[l][j] == 'p') {
            ++cnt;
            break;
        }
    }

    for (l = i - 1; l >= 0; --l) {
        if (board[l][j] == 'B' || board[l][j] == 'R') {
            break;
        }

        if (board[l][j] == 'p') {
            ++cnt;
            break;
        }
    }

    for (k = j - 1; k >= 0; --k) {
        if (board[i][k] == 'B' || board[i][k] == 'R') {
            break;
        }

        if (board[i][k] == 'p') {
            ++cnt;
            break;
        }
    }

    for (k = j + 1; k < col; ++k) {
        if (board[i][k] == 'B' || board[i][k] == 'R') {
            break;
        }

        if (board[i][k] == 'p') {
            ++cnt;
            break;
        }
    }

    return cnt;
}

int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int ret = 0;
    int i, j;
    for (i = 0; i < boardSize; ++i) {
        for (j = 0; j < boardColSize[i]; ++j) {
            if (board[i][j] == 'R') {
                ret = getPawn(i, j, board, boardSize, boardColSize[i]);
                break;
            }
        }
    }
    return ret;
}

```