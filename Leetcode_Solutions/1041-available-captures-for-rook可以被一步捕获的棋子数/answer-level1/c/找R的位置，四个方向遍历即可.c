### 解题思路
先寻找R的位置，然后向四个方向遍历，直到碰到卒或者象

### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int sum=0,i,j,m,n,q=0;
    //寻找R的位置坐标
    for(i=0;i<7;i++)
    {
        for(j=0;j<7;j++)
        {
            if(board[i][j]=='R')
            break;
        }
        if(board[i][j]=='R')
            break;
    }
    //向上寻找黑色的卒（pawn）
    m=i,n=j;
    for(q=0;q<7;q++)
    {
        if(board[m-1][n]=='p')
        {
            sum++;
            break;//找到上方向任意一个卒后，立即退出寻找
        }
        if(m-1==0||board[m-1][n]=='B')//数组边界检查
            break;
            m--;
    }
    //向下寻找黑色的卒（pawn）
    m=i,n=j;
    for(q=0;q<7;q++)
    {
        if(board[m+1][n]=='p')
        {
            sum++;
            break;
        }
        if(m+1==7||board[m+1][n]=='B')
            break;
            m++;
    }
    //向右寻找黑色的卒（pawn）
    m=i,n=j;
    for(q=0;q<7;q++)
    {
        if(board[m][n+1]=='p')
        {
            sum++;
            break;
        }
        if(n+1==7||board[m][n+1]=='B')
            break;
            n++;
    }
    //向左寻找黑色的卒（pawn）
    m=i,n=j;
    for(q=0;q<7;q++)
    {
        if(board[m][n-1]=='p')
        {
            sum++;
            break;
        }
        if(n-1==0||board[m][n-1]=='B')
            break;
            n--;
    }
        return sum;
}
```