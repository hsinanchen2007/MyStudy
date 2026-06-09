### 解题思路
借助一个与board同样大小的整型矩阵记录某一格子是否访问过，并在此基础上进行回溯，控制边界即使不是方阵也没关系

### 代码

```c
bool fillArr(char** board, int **follow, int boardSize, int* boardColSize, int x, int y, char * word)
{
    bool ret = false;
    // 回溯算法的终止条件，word长度为0说明所有字符都找到对应位置了，可以返回true
    if (strlen(word) == 0) {
        return true;
    }
    // 取字符串第一个字符作为目标字符
    char target = word[0];
    // 遍历上下左右四个相邻位置，如果没有发生越界，并且与目标字符相符，并且没有被访问过，则可以进入该分支
    if (x - 1 >= 0 && y < boardColSize[x - 1] && board[x - 1][y] == target && follow[x - 1][y] == 0) {
        // 伴随矩阵置为1，代表访问过
        follow[x - 1][y] = 1;
        // word + 1后继续在解空间中遍历
        ret = fillArr(board, follow, boardSize, boardColSize, x - 1, y, word + 1);
        // 同样，如果返回true说明找到了一个解，直接返回
        if (ret == true) {
            return ret;
        }
        // 否则说明该分支不存在解，需要回溯状态
        follow[x - 1][y] = 0;
    }
    if (x + 1 < boardSize && y < boardColSize[x + 1] && board[x + 1][y] == target && follow[x + 1][y] == 0) {
        follow[x + 1][y] = 1;
        ret = fillArr(board, follow, boardSize, boardColSize, x + 1, y, word + 1);
        if (ret == true) {
            return ret;
        }
        follow[x + 1][y] = 0;
    }
    if (y - 1 >= 0 && board[x][y - 1] == target && follow[x][y - 1] == 0) {
        follow[x][y - 1] = 1;
        ret = fillArr(board, follow, boardSize, boardColSize, x, y - 1, word + 1);
        if (ret == true) {
            return ret;
        }
        follow[x][y - 1] = 0;
    }
    if (y + 1 < boardColSize[x] && board[x][y + 1] == target && follow[x][y + 1] == 0) {
        follow[x][y + 1] = 1;
        ret = fillArr(board, follow, boardSize, boardColSize, x, y + 1, word + 1);
        if (ret == true) {
            return ret;
        }
        follow[x][y + 1] = 0;
    }
    return ret;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    // 一个与board大小相同的伴随矩阵follow，用来记录节点是否被访问过
    int **follow = (int **)malloc(sizeof(int *) * boardSize);
    int i, j;
    bool ret = false;
    // 申请内存，并所有节点都初始化为0，代表没有被访问过
    for(i = 0; i < boardSize; i++) {
        follow[i] = (int *)malloc(sizeof(int) * boardColSize[i]);
        memset(follow[i], 0, sizeof(int) * boardColSize[i]);
    }
    // 获取第一个目标字符
    char target = word[0];
    // 遍历board，找到所有与第一个字符相同的位置
    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize[i]; j++) {
            // 如果找到了目标字符
            if (target == board[i][j]) {
                // 首先将伴随矩阵对应位置置为1，代表访问过
                follow[i][j] = 1;
                // 并将该状态作为一个分支寻找解空间是否存在解
                ret = fillArr(board, follow, boardSize, boardColSize, i, j, word + 1);
                // 如果返回true说明找到了一个解，直接返回
                if (ret == true) {
                    return ret;
                }
                // 否则说明应该回溯到初始状态，伴随矩阵对应位置置回0
                follow[i][j] = 0;
            }
        }
    }
    return ret;
}
```