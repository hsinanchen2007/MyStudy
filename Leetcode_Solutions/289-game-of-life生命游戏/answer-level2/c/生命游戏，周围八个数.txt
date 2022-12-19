### 解题思路
此处撰写解题思路

### 代码

```c
//计算细胞周围存活数目
int count(int** board, int boardSize, int boardColSize, int i, int j){
    int num = 0;
    if (i){  //i不为第一行  i-1三种情况全部包括
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

    //计算 每一个细胞周围的值
    for (i = 0; i < boardSize; ++i)
        for (j = 0; j < boardColSize[0]; ++j)
            nums[i][j] = count(board, boardSize, boardColSize[0], i, j);

    for (i = 0; i < boardSize; ++i)
        for (j = 0; j < boardColSize[0]; ++j)
            board[i][j] = update(board, nums[i][j], i, j);
}

```JAVA：摘自雪姨 （刚学
/*
public class Solution {
    private static final int[] DX = {0, 0, 1, -1, 1, 1, -1, -1};
    private static final int[] DY = {1, -1, 0, 0, 1, -1, 1, -1};

    public void gameOfLife(int[][] board) {
        if (board.length == 0) {
            return;
        }
        int n = board.length;
        int m = board[0].length;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int cnt = 0;
                for (int k = 0; k < 8; k++) {
                    int x = i + DX[k];
                    int y = j + DY[k];
                    if (x < 0 || x >= board.length || y < 0 || y >= board[0].length) {
                        continue;
                    }
                    // 这里不能直接加board[x][y]，因为 board[x][y] 的倒数第二位是可能有值的。
                    cnt += board[x][y] & 1;
                }
                if ((board[i][j] & 1) > 0) {
                    // 这个是活细胞
                    if (cnt >= 2 && cnt <= 3) {
                        // 周围有2/3个活细胞，下一个状态还是活细胞。
                        board[i][j] = 0b11;
                    }
                    // 周围活细胞过多或过少都会死，因为原数据是0b01，所以这里不用额外赋值。
                } else if (cnt == 3) {
                    // 这个是死细胞，周围有3个活细胞，下一个状态变为活细胞。
                    board[i][j] = 0b10;
                }
            }
        }
        // 最后一位去掉，倒数第二位变为更新后的状态。
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
}