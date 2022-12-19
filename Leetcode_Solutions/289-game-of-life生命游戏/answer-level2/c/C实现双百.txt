### 解题思路
此处撰写解题思路

### 代码

```c
void gameOfLife(int** board, int boardSize, int* boardColSize){
    if (board == NULL || boardSize == 0 || *boardColSize == 0) return;
    int x_shift[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y_shift[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int res[boardSize][*boardColSize];
    memset(res, 0, sizeof(res));
    for (int i=0; i<boardSize; i++) {
        for (int j=0; j<*boardColSize; j++) {
            int sum = 0;
            for (int k=0; k<8; k++) {
                int xx = i + x_shift[k];
                int yy = j + y_shift[k];
                if (xx < 0 || xx >= boardSize || yy < 0 || yy>=*boardColSize) {
                    continue;
                }
                sum += board[xx][yy];
            }
            if (board[i][j] == 1 && (sum < 2 || sum > 3))
                res[i][j] = 0;
            else if (sum == 3)
                res[i][j] = 1;
            else
                res[i][j] = board[i][j];
        }
    }
    for (int i=0; i<boardSize; i++) {
        for (int j=0; j<*boardColSize; j++) {
            board[i][j] = res[i][j];
        }
    }
}
```