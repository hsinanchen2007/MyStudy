### 解题思路
![image.png](https://pic.leetcode-cn.com/d49e091263f74e4cb4fe6c136670b00c52b129079d54b96d7a68f56af2b7460e-image.png)


### 代码

```c
/* 矩阵中的路径 递归 +枚举 + 剪枝 */
bool find(char **board, int boardSize, int boardColSize, int i, int j,
          int **flag, int index, char *word)
{
    bool ans;

    //C语言字符串 注意以' \0'结束
    if (word[index] == '\0') { 
        return true;
    }
    
    if ((i < 0) || (i >= boardSize) || (j < 0) || (j >= boardColSize)) {
        return false;
    }

    if (flag[i][j] == 1) {
        return false;
    }

    if (board[i][j] != word[index]) {
        return false;
    }
    
    flag[i][j] = 1;

    ans = find(board, boardSize, boardColSize, i + 1, j, flag, index + 1, word) ||
          find(board, boardSize, boardColSize, i - 1, j, flag, index + 1, word) || 
          find(board, boardSize, boardColSize, i, j + 1, flag, index + 1, word) ||
          find(board, boardSize, boardColSize, i, j - 1, flag, index + 1, word);
    
    flag[i][j] = 0; // 回溯
    return ans;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word){
    int **stepFlag = (int **)malloc(sizeof(int *) * boardSize);
    for (int k = 0; k < boardSize; k++) {
        stepFlag[k] = (int *)malloc(sizeof(int) * (*boardColSize));
        memset(stepFlag[k], 0x0, sizeof(int) * (*boardColSize));
    }
    // memset(*stepFlag, 0x0, sizeof(int) * boardSize * (*boardColSize));

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            if (find(board, boardSize, *boardColSize, i, j, stepFlag, 0, word) == true) {
                return true;
            }
        }
    }

    return false;
}
```