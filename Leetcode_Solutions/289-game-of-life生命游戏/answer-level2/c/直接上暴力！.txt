### 解题思路
![1.jpg](https://pic.leetcode-cn.com/710c685e19df55276978fdc41273c0691b9291e24c0259d0d8c25cfe8cff0150-1.jpg)

暴力求解O(m*n)：
计算出每一个细胞周围存活的细胞数目O(m*n)。
根据相应数目改变自身状态O(m*n)。

### 代码

```c
//计算细胞周围存活数目
int count(int** board, int boardSize, int boardColSize, int i, int j){
    int num = 0;
    if (i){
        num += board[i - 1][j];
        if (j)
            num += board[i - 1][j - 1];
        if ((j + 1) < boardColSize)
            num += board[i - 1][j + 1];
    }
    if (j)
        num += board[i][j - 1];
    if ((j + 1) < boardColSize)
        num += board[i][j + 1];
    if ((i + 1) < boardSize){
        num += board[i + 1][j];
        if (j)
            num += board[i + 1][j - 1];
        if ((j + 1) < boardColSize)
            num += board[i + 1][j + 1];
    }
    return num;
}

//更新细胞状态
int update(int** board, int num, int i, int j){
    if (board[i][j]){
        if (num < 2 || num > 3)
            return 0;
        return 1;
    }
    if (num == 3)
        return 1;
    return 0;
}

void gameOfLife(int** board, int boardSize, int* boardColSize){
    if (!boardColSize[0] || !boardSize)
        return ;
    int nums[boardSize][boardColSize[0]];// nums数组储存细胞周围存活数目
    int i = 0, j = 0;
    for (i = 0; i < boardSize; ++i)
        for (j = 0; j < boardColSize[0]; ++j)
            nums[i][j] = count(board, boardSize, boardColSize[0], i, j);

    for (i = 0; i < boardSize; ++i)
        for (j = 0; j < boardColSize[0]; ++j)
            board[i][j] = update(board, nums[i][j], i, j);
}
```