### 解题思路
简单遍历即可。

### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int X, Y;
    int cnt = 0;
    for (int i  = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 'R') {
                X = i;
                Y = j;
            }
        }
    }
    for (int i = (Y - 1); i >= 0; i--) {
        if (board[X][i] == 'p') {
            cnt++;
            break;
        }
        if (board[X][i] == 'B') {
            break;
        }
    }
    for (int i = (Y + 1); i < 8; i++) {
        if (board[X][i] == 'p') {
            cnt++;
            break;
        }
        if (board[X][i] == 'B') {
            break;
        }
    }
    for (int i = (X - 1); i >= 0; i--) {
        if (board[i][Y] == 'p') {
            cnt++;
            break;
        }
        if (board[i][Y] == 'B') {
            break;
        }
    }
    for (int i = (X + 1); i < 8; i++) {
        if (board[i][Y] == 'p') {
            cnt++;
            break;
        }
        if (board[i][Y] == 'B') {
            break;
        }
    }
    return cnt;
}
```