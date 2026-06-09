### 解题思路
1.定义8个方向的运动向量，遍历查找每个位置，计算1出现的次数，通过规则进行判断，保存在临时变量中，然后重新赋值给原数组。

### 代码

```c
void gameOfLife(int** board, int boardSize, int* boardColSize){
    int xShift[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int yshift[] = {-1, -1, -1, 0, 0 ,1, 1, 1};
    int *tmp = (int *)malloc(sizeof(int) * boardSize * boardColSize[0]);
    int i, j, k;
    int count = 0;
    int xx = 0;
    int yy = 0;
    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize[0]; j++) {
            count = 0;
            for (k = 0; k < 8; k++) {
               xx = i + xShift[k];
               yy = j + yshift[k];
                if (xx < 0 || xx >= boardSize || yy < 0 || yy >= boardColSize[0])
                    continue;
                else {
                    if (board[xx][yy] == 1)
                        count++;
                }
            }
            if (board[i][j] == 0){
                if (count == 3) 
                    tmp[i * boardColSize[0] + j] = 1;
                else
                    tmp[i * boardColSize[0] + j] = 0;
            } else {
                if (count == 2 || count == 3)
                    tmp[i * boardColSize[0] + j] = 1;
                else
                    tmp[i * boardColSize[0] + j] = 0;
            }
        }
    }

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize[0]; j++) {
            board[i][j] = tmp[i * boardColSize[0] + j];
        }
    }

    free(tmp);
}
```