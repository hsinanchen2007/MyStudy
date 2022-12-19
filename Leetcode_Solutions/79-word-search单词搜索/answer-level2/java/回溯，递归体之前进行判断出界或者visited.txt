### 解题思路
此处撰写解题思路
网格全回溯，注意的点是不能再回溯里面判断是否出界跟是够visited，应该再进入回溯之前判断，这样不会超时。
### 代码

```java
class Solution {
    public  boolean[][] visited;
    public  String word;
    public int [] dir_x=new int[]{0,1,0,-1};
    public int[] dir_y=new int[]{1,0,-1,0};
    public char[][] board;
    public int m;
    public int n;
    public boolean exist(char[][] board, String word) {
        this.m=board.length;
        this.n= this.m==0? 0:board[0].length;
        visited=new boolean[m][n];
        this.word=word;
        this.board=board;
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (explore(i,j,0))
                    return true;
            }
        }
        return  false;
    }
    public boolean explore(int x,int y,int start)
    {
       if (start==word.length()-1)
       {
           return board[x][y]==word.charAt(start);
       }
       if (board[x][y]==word.charAt(start))
       {

           int count=4;

           visited[x][y]=true;
           while(count>0)
           {
               count--;
               if (inArea(x+dir_x[count],y+dir_y[count]) && !visited[x+dir_x[count]][y+dir_y[count]])
                   if (explore(x+dir_x[count],y+dir_y[count],start+1))
                       return true;
           }

           visited[x][y]=false;

       }
        return false;
    }
    public boolean inArea(int x, int y)
    {
        return x>=0 && x<m && y>=0 && y<n;
    }
}

```