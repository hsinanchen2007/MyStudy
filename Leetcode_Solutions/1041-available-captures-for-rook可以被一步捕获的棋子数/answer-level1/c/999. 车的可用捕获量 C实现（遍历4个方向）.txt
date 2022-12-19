### 解题思路
    循环部分代码重复量大，可以考虑抽方法，懒，不考虑怎么抽了

### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize)
{
    int i, j;
    bool find = false;
    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardSize; j++) {
            if (board[i][j] == 'R') {
                find = true;
                break;
            }
        }
        if (find) {
            break;
        }
    }
    int cnt = 0;
    for (int r = i - 1; r > 0; r--) {
        if (board[r][j] != '.') {
            if (board[r][j] == 'p') {
                cnt++;

            }
            break;
        }
    }
    for (int r = i + 1; r < boardSize; r++) {
        if (board[r][j] != '.') {
            if (board[r][j] == 'p') {
                cnt++;
            }
            break;
        }
    }
    for (int c = j - 1; c > 0; c--) {
        if (board[i][c] != '.') {
            if (board[i][c] == 'p') {
                cnt++;
            }
            break;
        }
    }
    for (int c = j + 1; c < boardSize; c++) {
        if (board[i][c] != '.') {
            if (board[i][c] == 'p') {
                cnt++;
            }
            break;
        }
    }
    return cnt;
}
```