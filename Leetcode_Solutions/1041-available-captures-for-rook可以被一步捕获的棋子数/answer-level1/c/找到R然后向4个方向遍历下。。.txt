如题。

### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int i;
    int j;
    int flag = 0;
    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == 'R') {
                flag = 1;
                break;
            }
        }
        if (flag) break;
        
    }

    int cnt = 0;
    for (int x = i; x >= 0; x--) {
        if (board[x][j] == 'B') break;
        if (board[x][j] == 'p') {
            cnt += 1;
            break;
        }
    }


    for (int x = i; x < boardSize; x++) {
        if (board[x][j] == 'B') break;
        if (board[x][j] == 'p') {
            cnt += 1;
            break;
        }
    }

    for (int y = j; y >= 0; y--) {
        if (board[i][y] == 'B') break;
        if (board[i][y] == 'p') {
            cnt += 1;
            break;
        }
    }

    for (int y = j; y < boardColSize[0]; y++) {
        if (board[i][y] == 'B') break;
        if (board[i][y] == 'p') {
            cnt += 1;
            break;
        }
    }
    return cnt;
}
```