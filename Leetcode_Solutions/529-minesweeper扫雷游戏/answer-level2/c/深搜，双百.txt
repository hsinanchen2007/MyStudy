这个题目大概的意思是题目给予我们一个坐标，根据坐标里面的值进行不同情况的判断。
第一如果是地雷，我们就结束。
第二如果是靠近地雷的‘E’我们就单独的进行进行统计数字，结束。
第三如果是不靠近地雷的‘E’,我们就把这个位置的上、下、左、右、左上、左下、右上、右下进行遍历
希望对大家有帮助

```
int juge(int x, int y, char** board, int m, int n)//这个函数的目的是为了判断那个数字是否靠近地雷，如果靠近就统计数字。
{
    int sum = 0;
    // 从8个方向进行统计
    if(x - 1 >= 0)
    {
        if(board[x - 1][y] == 'M')
            sum++;
        if(y - 1 >= 0 && board[x - 1][y - 1] == 'M')
            sum++;
        if(y + 1 < n && board[x - 1][y + 1] == 'M')
            sum++;
    }
    if(y - 1 >= 0 && board[x][y - 1] == 'M')
        sum++;
    if(y + 1 < n && board[x][y + 1] == 'M')
        sum++;
    if(x + 1 < m)
    {
        if(board[x + 1][y] == 'M')
            sum++;
        if(y - 1 >= 0 && board[x + 1][y - 1] == 'M')
            sum++;
        if(y + 1 < n && board[x + 1][y + 1] == 'M')
            sum++;
    }
    return sum;
} 
void dfs(int x, int y, char** board, int m, int n)
{
    int fi = 0;
    fi = juge(x, y, board, m, n);
    if(fi > 0)//如果靠经地雷就结束。
    {
        board[x][y] = fi + '0';
    }
    else//否则就进行8各方向的深搜。
    {
        board[x][y] = 'B';
        if(x + 1 < m)
        {
            if(board[x + 1][y] == 'E')
                dfs(x + 1, y, board, m, n);
            if(y + 1  < n && board[x + 1][y + 1] == 'E')
                dfs(x + 1, y + 1, board, m, n);
            if(y - 1 >= 0 && board[x + 1][y - 1] == 'E')
                dfs(x + 1, y - 1, board, m, n);
        }
        if(x - 1 >= 0 )
        {
            if(board[x - 1][y] == 'E')
                dfs(x - 1, y, board, m, n);
            if(y + 1  < n && board[x - 1][y + 1] == 'E')
                dfs(x - 1, y + 1, board, m, n);
            if(y - 1 >= 0 && board[x - 1][y - 1] == 'E')
                dfs(x - 1, y - 1, board, m, n);
        }
        if(y + 1 < n && board[x][y + 1] == 'E')
        {
            dfs(x, y + 1, board, m, n);
        }
        if(y - 1 >= 0 && board[x][y - 1] == 'E')
        {
            dfs(x, y - 1, board, m, n);
        }
    }
}
char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes){
    int i;
    *returnSize = boardSize;
    *returnColumnSizes = boardColSize;
    if(board[click[0]][click[1]] == 'M')
    {
        board[click[0]][click[1]] = 'X';
        return board;
    }
    dfs(click[0], click[1], board, boardSize, boardColSize[0]);
    return board;
}
```