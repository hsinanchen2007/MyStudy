### 解题思路
上代码

### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int rx;
    int ry;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == 'R') {
                rx = i;
                ry = j;
            }
        }
    }
    int ret = 0;
    for (int i = rx; i >= 0; i--) {
        if (board[i][ry] == 'B') {
            break;
        } else if (board[i][ry] == 'p') {
            ret++;
            break;
        }
    }
    for (int i = rx; i <= boardColSize[0] - 1; i++) {
        if (board[i][ry] == 'B') {
            break;
        } else if (board[i][ry] == 'p') {
            ret++;
            break;
        }
    }
    for (int i = ry; i >= 0; i--) {
        if (board[rx][i] == 'B') {
            break;
        } else if (board[rx][i] == 'p') {
            ret++;
            break;
        }
    }
        for (int i = ry; i <= boardSize - 1; i++) {
        if (board[rx][i] == 'B') {
            break;
        } else if (board[rx][i] == 'p') {
            ret++;
            break;
        }
    }
    return ret;
}
```