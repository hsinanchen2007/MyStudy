```

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
int find (char** board, int boardSize, int dir, int x, int y);
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int x, y, ret = 0;
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (board[i][j] == 'R') {
                x = i;
                y = j;
                break;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        ret += find(board, boardSize, i, x, y);
    }
    return ret;
}

int find (char** board, int boardSize, int dir, int x, int y) {
    if (x > 7 || x < 0 || y > 7 || y < 0) {
        return 0;
    }
    if (board[x][y] == 'B') {
        return 0;
    }
    if (board[x][y] == 'p') {
        return 1;
    }
    switch (dir) {
        case UP : return find(board, boardSize, dir, x - 1, y);
        case RIGHT: return find(board, boardSize, dir, x, y + 1);
        case DOWN: return find(board, boardSize, dir, x + 1, y);
        case LEFT: return find(board, boardSize, dir, x, y - 1);
    }
    return 0;
}
```
