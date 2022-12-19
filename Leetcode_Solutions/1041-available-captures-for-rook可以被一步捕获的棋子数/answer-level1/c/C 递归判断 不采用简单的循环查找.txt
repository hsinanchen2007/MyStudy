### 解题思路
先找到R，然后对R的四个方向进行判断，遇到.就接着走下去，遇到p直接返回1，遇到B直接退出当前的递归，即结束当前方向。

### 代码

```c
int find_p(char** board, int boardSize, int boardColSize, int i, int j, char pointer) {
    if (i < 0 || i >= boardSize || j < 0 ||j >= boardColSize) {
        return 0;
    }

    if (board[i][j] == 'B') {
        return 0;
    }

    if (board[i][j] == 'p') {
        return 1;
    }

    if (board[i][j] == '.') {
        int res;
        switch (pointer) {
            case 'W':
                res = find_p(board, boardSize, boardColSize, i - 1, j, pointer);
                break;
            case 'E':
                res = find_p(board, boardSize, boardColSize, i + 1, j, pointer);
                break;
            case 'S':
                res = find_p(board, boardSize, boardColSize, i, j - 1, pointer);
                break;
            case 'N':
                res = find_p(board, boardSize, boardColSize, i, j + 1, pointer);
                break;
        }
        return res;
    }

    return 0;
}


int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int count = -1;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            if(board[i][j] == 'R') {
                count = 0;
                int res = 0;
                char pointer = 'W';
                res = find_p(board, boardSize, *boardColSize, i - 1, j, pointer);
                count += res;
                pointer = 'E';
                res = find_p(board, boardSize, *boardColSize, i + 1, j, pointer);
                count += res;
                pointer = 'S';
                res = find_p(board, boardSize, *boardColSize, i, j - 1, pointer);
                count += res;
                pointer = 'N';
                res = find_p(board, boardSize, *boardColSize, i, j + 1, pointer);
                count += res;
                break;
            }
        }

        if (count != -1) {
            break;
        }
    }

    return count;
}
```