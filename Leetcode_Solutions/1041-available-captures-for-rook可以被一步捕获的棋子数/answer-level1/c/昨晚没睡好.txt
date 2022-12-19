### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/607c778ff499fadf110e87c5ffbc4a042806024d276bab66ba3431d3625ad09d-image.png)

### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int row, col;
    row = col = -1;

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == 'R') {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1 && col != -1) {
            break;
        }
    }

    if (row == -1 || col == -1) {
        return 0;
    }

    int ans = 0;
    //printf("row = %d, col = %d\n", row, col);

    //up
    int i = row - 1;
    while (i >= 0) {
        if (board[i][col] == 'p') {
            ans += 1;
            break;
        }
        if (board[i][col] == '.') {
            i--;
            continue;
        }
        if (board[i][col] == 'B') {
            break;
        }
    }
    //printf("ans = %d\n", ans);

    //down
    i = row + 1;
    while (i < boardSize) {
        if (board[i][col] == 'p') {
            ans += 1;
            break;
        }
        if (board[i][col] == '.') {
            i++;
            continue;
        }
        if (board[i][col] == 'B') {
            break;
        }
    }
    //printf("ans = %d\n", ans);

    //left
    int j = col - 1;
    while (j >= 0) {
        if (board[row][j] == 'p') {
            ans += 1;
            break;
        }
        if (board[row][j] == '.') {
            j--;
            continue;
        }
        if (board[row][j] == 'B') {
            break;
        }
    }
    //printf("ans = %d\n", ans);

    //right
    j = col + 1;
    while (j < boardColSize[row]) {
        if (board[row][j] == 'p') {
            ans += 1;
            break;
        }
        if (board[row][j] == '.') {
            j++;
            continue;
        }
        if (board[row][j] == 'B') {
            break;
        }
    }
    //printf("ans = %d\n", ans);

    return ans;
}
```