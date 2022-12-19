### 解题思路
此处撰写解题思路

### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    if (board == NULL || boardSize == 0 || boardColSize == 0) {
        return -1;
    }

    int pos_x, pos_y;
    int i, j, flag = 0;
    int count = 0;

    for (pos_x = 0; pos_x < boardSize; pos_x++) {
        for (pos_y = 0; pos_y < boardColSize[pos_x]; pos_y++) {
            if (board[pos_x][pos_y] == 'R') {
                flag = 1;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

    if (pos_x == boardSize - 1 && pos_y == boardColSize[pos_x] - 1) {
        return -1;
    }

    for (i = pos_x; i < boardSize; i++) {
        if (board[i][pos_y] == 'p') {
            count++;
            break;
        }

        if (board[i][pos_y] == 'P' || board[i][pos_y] == 'B' || board[i][pos_y] == 'b') {
            break;
        }
    }

    for (i = pos_x; i >= 0; i--) {
        if (board[i][pos_y] == 'p') {
            count++;
            break;
        }

        if (board[i][pos_y] == 'P' || board[i][pos_y] == 'B' || board[i][pos_y] == 'b') {
            break;
        }
    }

    for (j = pos_y; j >= 0; j--) {
        if (board[pos_x][j] == 'p') {
            count++;
            break;
        }

        if (board[pos_x][j] == 'P' || board[pos_x][j] == 'B' || board[pos_x][j] == 'b') {
            break;
        }
    }

    for (j = pos_y; j < boardColSize[pos_x]; j++) {
        if (board[pos_x][j] == 'p') {
            count++;
            break;
        }

        if (board[pos_x][j] == 'P' || board[pos_x][j] == 'B' || board[pos_x][j] == 'b') {
            break;
        }
    }

    return count;

}
```