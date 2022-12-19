### 解题思路
由于和边界O相连的所有O都不能被记为X，所以我们先扫描边界，遇到O时，利用递归找出与之相连的所有O，用二位数组`t[i][j]`记录为`true`。
第一步所有工作完成后直接扫描`board`的中间部分，如果`board[i][j]=='O'&&t[i][j]==false`,则需要转换为X。

最后执行用时2ms
### 代码

```java
class Solution {

    boolean v[][],t[][];//v[][]记录访问过的位置。
    private void fillTransfer(int x,int y,char[][] board)
    {
        
        if(x<0||y<0||x>=board.length||y>=board[0].length||board[x][y]=='X')           
            return;
        if(t[x][y]||v[x][y])//访问过或者已经确定为无需转换的
            return;
        
        v[x][y]=true;
        if(board[x][y]=='O')t[x][y]=true;
        fillTransfer(x-1,y,board);
        fillTransfer(x+1,y,board);
        fillTransfer(x,y-1,board);
        fillTransfer(x,y+1,board);
    
    }
    public void solve(char[][] board) 
    {
        if(board.length<3||board[0].length<3)
            return;
        int r=board.length,c=board[0].length;
        v=new boolean[r][c];
        t=new boolean[r][c];
    
        //visit boarder to fill transfer
        for(int i=0;i<r;i++)
        {
            if(i!=0&&i!=r-1)
            {
                if(board[i][0]=='O')
                    fillTransfer(i,0,board);
                if(board[i][c-1]=='O')
                    fillTransfer(i,c-1,board);
                continue;
            }
            for(int j=0;j<c;j++)
            {
                if(board[i][j]=='O')
                    fillTransfer(i,j,board);
            }
        }
    
        for(int i=1;i<r-1;i++)
            for(int j=1;j<c-1;j++)
                if(!t[i][j])
                    board[i][j]='X';
    }
}
```