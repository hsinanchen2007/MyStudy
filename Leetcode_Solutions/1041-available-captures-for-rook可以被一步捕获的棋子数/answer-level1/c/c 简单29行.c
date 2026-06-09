```
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int res = 0;
    int x, y;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == 'R') {
                x = i;
                y = j;
            }
        }
    }
    int vert[4] = {-1,0,1,0};
    int horiz[4] = {0,-1,0,1};
    for (int i = 0; i < 4; i++) {
        int x1 = x, y1 = y;
        while (1) {
            x1 += vert[i];
            y1 += horiz[i];
            if (x1 < 0 || x1 >= boardSize || y1 < 0 || y1 >= boardColSize[0]) break;
            else if (board[x1][y1] == '.') continue;
            else if (board[x1][y1] == 'B') break;
            else if (board[x1][y1] == 'p') {
                res++;
                break;
            }
        }
    }
    return res;
}
```
