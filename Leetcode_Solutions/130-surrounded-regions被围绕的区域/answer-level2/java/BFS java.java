### 解题思路
bfs

### 代码

```java
class Solution {
    public class point{//坐标的数据类型
        int x,y;
        point(int x,int y)
        {
            this.x=x;
            this.y=y;
        }
    }
    public void solve(char[][] board) {//BFS从边缘上的0开始遍历
      if (board.length==0)
      return;
      boolean[][] notsur=new boolean[board.length][board[0].length];//标记不用填充的0
      Queue<point> q=new LinkedList<point>();
      for(int i=0;i<board.length;i++)//将边缘上的点都入队列
        {
        if(board[i][0]=='O')
         q.add(new point(i,0));
        if(board[i][board[0].length-1]=='O')
         q.add(new point(i,board[0].length-1));
            }   
      for(int i=0;i<board[0].length;i++)
       { if(board[0][i]=='O')
         q.add(new point(0,i));
         if(board[board.length-1][i]=='O')
         q.add(new point(board.length-1,i));
       }
       while(q.size()>0)
       {
           point p=q.poll();//出队列，并将所有与该点相邻的0都入队
           notsur[p.x][p.y]=true;
           if(p.x+1<board.length&&board[p.x+1][p.y]=='O'&&!notsur[p.x+1][p.y])
            q.add(new point(p.x+1,p.y));
           if(p.x-1>0&&board[p.x-1][p.y]=='O'&&!notsur[p.x-1][p.y])
            q.add(new point(p.x-1,p.y));
           if(p.y-1>0&&board[p.x][p.y-1]=='O'&&!notsur[p.x][p.y-1])
            q.add(new point(p.x,p.y-1));
           if(p.y+1<board[0].length&&board[p.x][p.y+1]=='O'&&!notsur[p.x][p.y+1])
            q.add(new point(p.x,p.y+1));           
       }
       for(int j=0;j<board.length;j++)
        for(int k=0;k<board[0].length;k++)
        {
            if(board[j][k]=='O'&&notsur[j][k]!=true)
             board[j][k]='X';
        }

    }
}
```