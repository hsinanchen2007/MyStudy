### 解题思路
1.将内部的'O'暂时换为'Y'，作为区分标记；
2.从边缘'O'向里走,遇到'Y'，就将'Y'改为'O',直到接触不到'Y'；
3.剩下的'Y'即为符合题目要求的'O',将他们改为'X'.

### 代码

```c
void bfs(char** board, int x, int y,int n,int m) {
    if(x-1>0 && y>0 && y<m-1 && board[x-1][y]=='Y')
    {//向上走
        board[x-1][y]='O';
        bfs(board,x-1,y,n,m);
    }
    if(x+1<n-1 && y>0 && y<m-1 && board[x+1][y]=='Y')
    {//向下走
        board[x+1][y]='O';
        bfs(board,x+1,y,n,m);
    }
    if(y-1>0 && x>0 && x<n-1 && board[x][y-1]=='Y')
    {//向左走
        board[x][y-1]='O';
        bfs(board,x,y-1,n,m);
    }
    if(y+1<m-1 && x>0 && x<n-1 && board[x][y+1]=='Y')
    {//向右走
        board[x][y+1]='O';
        bfs(board,x,y+1,n,m);
    }
}
void solve(char** board, int boardSize, int* boardColSize){
    int x=boardSize;
    int y=boardColSize[0];
    int i,j;
    if(boardSize==0||boardColSize[0]==0)
        return ;
    if(x>2&&y>2)
    {       
        for(i=1; i<x-1; i++)        
            for(j=1; j<y-1; j++)            
                if(board[i][j]=='O')
                    board[i][j]='Y';//'O'（内）为'Y'，作为区分记号                    
        for(i=0; i<x; i++)
            for(j=0; j<y; j++)
                if(board[i][j]=='O'&&(i==0||i==x-1||j==0||j==y-1))
                    bfs(board,i,j,x,y);//只取边缘的'O'作为初始检查点，修改记号
        for(i=1; i<x-1; i++)
            for(j=1; j<y-1; j++)
                if(board[i][j]=='Y')//查找后符号要求的'O'改为'X'
                    board[i][j]='X';
    }
}
```