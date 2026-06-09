```
#define LINE 10
#define ORIGIN "123456789."
char strRow[LINE - 1][LINE + 1];
char strCol[LINE - 1][LINE + 1];
char strSqr[LINE - 1][LINE + 1];

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    for (int i = 0; i < LINE - 1; i++) {
        memcpy(strRow[i], ORIGIN, LINE);
        memcpy(strCol[i], ORIGIN, LINE);
        memcpy(strSqr[i], ORIGIN, LINE);
    }
    char *tmp;
    for (int m = 0; m < boardSize; m++) {
        for (int n = 0; n < *boardColSize; n++) {
            tmp = strchr(strRow[m], board[m][n]);
            if (tmp != NULL) {
                *tmp = '.';
            } else {
                return false;
            }
            tmp = strchr(strCol[m], board[n][m]);
            if (tmp != NULL) {
                *tmp = '.';
            } else {
                return false;
            }
            tmp = strchr(strSqr[m], board[m/3*3 + n/3][m%3*3 + n%3]);
            if (tmp != NULL) {
                *tmp = '.';
            } else {
                return false;
            }
        }
    }
    return true;
}
```
