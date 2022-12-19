### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/dc232a9c691dea620ee333132e4b9a15bbc0cb1fe86066b6404054a118eacb21-%E6%8D%95%E8%8E%B7.PNG)

将生命状态改变的细胞设成一个除0、1之外的值，通过判断这个值可以知道初始时的存活与否。
最后在统一改为改变后的状态。

### 代码

```c
int initvalue(int val){
    if(val == 2)
        return 0;
    if(val == 3)
        return 1;
    return val;
}

int nowvalue(int val){
    if(val == 2)
        return 1;
    if(val == 3)
        return 0;
    return val;
}

void gameOfLife(int** board, int boardSize, int* boardColSize){
    int m = boardSize, n = *boardColSize, count, i, j;

    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            count = 0;

            if(i > 0 && j > 0)
                count += initvalue(board[i-1][j-1]);

            if(i > 0)
                count += initvalue(board[i-1][j]);

            if(i > 0 && j < n-1)
                count += initvalue(board[i-1][j+1]);

            if(j > 0)
                count += initvalue(board[i][j-1]);

            if(j < n-1)
                count += initvalue(board[i][j+1]);

            if(i < m-1 && j > 0)
                count += initvalue(board[i+1][j-1]);

            if(i < m-1)
                count += initvalue(board[i+1][j]);

            if(i < m-1 && j < n-1)
                count += initvalue(board[i+1][j+1]);

            if(board[i][j] == 0 && count == 3)
                board[i][j] = 2;
            
            if(board[i][j] == 1 && count != 2 && count != 3 )
                board[i][j] = 3;
        }
    }

    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            board[i][j] = nowvalue(board[i][j]);
}
```