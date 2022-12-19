### 解题思路
看官方的吧；
![image.png](https://pic.leetcode-cn.com/f21d9f997ed5da5794dca9ad2dfe49aa60ee8ff8271a001f6dab1a9b44ab9767-image.png)

### 代码

```c
bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    if (board == NULL) {
        return false;
    }
    int **arrR = (int **)calloc(sizeof(int*), boardSize);
    int **arrH = (int **)calloc(sizeof(int*), boardSize);
    int **arrS = (int **)calloc(sizeof(int*), boardSize);
    for (int i = 0; i < boardSize; i++) {
        arrR[i] = (int *)calloc(sizeof(int), *boardColSize + 1);
        arrH[i] = (int *)calloc(sizeof(int), *boardColSize + 1);
        arrS[i] = (int *)calloc(sizeof(int), *boardColSize + 1);
    }
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            char num = board[i][j];
            if (num != '.') { 
               int n = board[i][j] - '0';
               int box_index = (i / 3 ) * 3 + j / 3;
               arrR[i][n] += 1;
               arrH[j][n] += 1;
               arrS[box_index][n] += 1;
               if (arrR[i][n] > 1 || arrH[j][n] > 1 || arrS[box_index][n] > 1) {
                   return false;
               }
            }
        }
    }
    for (int i = 0; i < boardSize; i++) {
        free(arrR[i]);
        free(arrH[i]);
        free(arrS[i]);
    }
    free(arrR);
    free(arrH);
    free(arrS);
    return true;
}
```