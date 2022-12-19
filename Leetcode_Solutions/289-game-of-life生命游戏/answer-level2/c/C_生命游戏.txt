### 解题思路
没什么技巧性，从头到尾遍历矩阵，检查四周八个位置的元素，做出改变。
原地的处理：
本来是1，需变成0，就改成-1；本来是0，需变成1，就记成-2.判断的时候把-1也当成1判断，判断统计完之后再彻底改动成1和0

### 代码

```c
int aliveAround(int** Board,int BoardSize,int* BoardColSize, int Row,int Col)
{
    int result=0;
    if(Row-1>=0)
    {
        if(Col-1>=0&&(Board[Row-1][Col-1]==1||Board[Row-1][Col-1]==-1))++result;
        if(Board[Row-1][Col]==1||Board[Row-1][Col]==-1)++result;
        if(Col+1<BoardColSize[Row-1]&&(Board[Row-1][Col+1]==1||Board[Row-1][Col+1]==-1))++result;
    }
    if(Row+1<BoardSize)
    {
        if(Col-1>=0&&(Board[Row+1][Col-1]==1||Board[Row+1][Col-1]==-1))++result;
        if(Board[Row+1][Col]==1||Board[Row+1][Col]==-1)++result;
        if(Col+1<BoardColSize[Row+1]&&(Board[Row+1][Col+1]==1||Board[Row+1][Col+1]==-1))++result;
    }
    if(Col-1>=0&&(Board[Row][Col-1]==1||Board[Row][Col-1]==-1))++result;
    if(Col+1<BoardColSize[Row]&&(Board[Row][Col+1]==1||Board[Row][Col+1]==-1))++result;
    return result;
}

void gameOfLife(int** board, int boardSize, int* boardColSize){
    for(int row=0;row<boardSize;++row)
        for(int col=0;col<boardColSize[row];++col)
            {
                int num=aliveAround(board,boardSize,boardColSize,row,col);
                if(board[row][col]==1) 
                    if(num<2||num>3)
                        board[row][col]=-1;   
                if(num==3&&board[row][col]==0)
                    board[row][col]=-2;
            }

    for(int row=0;row<boardSize;++row)
        for(int col=0;col<boardColSize[row];++col)
            if(board[row][col]==-1)board[row][col]=0;
            else if(board[row][col]==-2)board[row][col]=1;
}
```