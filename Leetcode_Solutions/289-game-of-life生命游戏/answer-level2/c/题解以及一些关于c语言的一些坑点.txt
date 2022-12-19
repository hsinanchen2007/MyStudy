### 解题思路
这个题目比较坑，一开始我以为board的实参是一个二维数组，但实际上它是一个指针数组，换句话说数据并不在一块连续的内存上。
（如果传递进来的是二维数组则board[i][j]的写法是不正确的，因为指针的步长未知）题目本身没什么可说的，用另一个变量临时记录
就完事了。

### 代码

```c
int calValue(int **map, int i, int j, int i_max, int j_max) {
    int result = 0;
    int i_tmp, j_tmp;
    static int dir[8][2] = {{-1, -1},{-1, 0},{-1, 1},{0,  -1},{0,  1},{1,  -1},{1,  0},{1,  1}};
    for (int c = 0; c < 8; ++c) {
        i_tmp = i + dir[c][0];
        j_tmp = j + dir[c][1];
        if (i_tmp < 0 || i_tmp >= i_max || j_tmp < 0 || j_tmp >= j_max) continue;
        result += map[i_tmp][j_tmp] == 1 || map[i_tmp][j_tmp] == 3 ? 1 : 0;
    }
    return result;
}


void gameOfLife(int **board, int boardSize, int *boardColSize) {

    for (int i = 0; i < boardSize; ++i)
        for (int j = 0; j < boardColSize[i]; ++j) {
            int result = calValue(board,i,j,boardSize,boardColSize[i]);
            int self = board[i][j];
            if(self == 1 && (result < 2 || result >3 ))
                board[i][j] = 3;
            if(self == 0 && (result == 3))
                board[i][j] = 2;
        }
    for(int i = 0;i<boardSize;++i)
        for(int j = 0;j < boardColSize[i];++j) {
            if(board[i][j] == 3)
                board[i][j] = 0;
            if(board[i][j] == 2)
                board[i][j] = 1;
        }
}
```