### 解题思路
矩阵运算:
1. 两次遍历，并用中间值做特殊标记；
2. 矩阵附近坐标变化用坐标实现循环遍历，便于统一处理边界问题；

### 代码

```c
/* 矩阵运算:
1. 两次遍历，并用中间值做特殊标记；
2. 矩阵附近坐标变化用坐标实现循环遍历，便于统一处理边界问题；
 */
void gameOfLife(int** board, int boardSize, int* boardColSize){
    int pos[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, 
                    {0, -1}, {0, 1},
                    {1, -1}, {1, 0}, {1, 1}};
    int i, j, k;
    int alive;

    if (board == NULL) {
        return;
    }

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize[i]; j++) {
            alive = 0;
            for (k = 0; k < 8; k ++) {
                int x, y;
                x = i + pos[k][0];
                y = j + pos[k][1];

                if (x < 0 || x > boardSize - 1 || y < 0 || y > boardColSize[i] - 1) {
                    continue;
                }

                if (board[x][y] == 1 || board[x][y] == -1 ) {
                    alive++;
                }
            }
            /* 0->1: 标记成2； 1 ->0: 标记成-1 */
            if (board[i][j] == 1 && (alive < 2 || alive > 3)) {
                board[i][j] = -1;
            } 

            if (board[i][j] == 0 && alive == 3) {
                board[i][j] = 2;
            } 
        }
    }

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == -1) {
                board[i][j] = 0;
            } else if (board[i][j] == 2) {
                board[i][j] = 1;
            }
        }
    }

}
```