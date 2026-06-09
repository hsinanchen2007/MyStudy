### 代码

```java
class Solution {
    int n,m,ji;
    int [][] grid;
    int ans=0;
    int [] []dir;
    public int uniquePathsIII(int[][] grid) {
        this.grid=grid;
        n=grid.length;
        m=grid[0].length;
        dir=new int [][]{{0,1},{1,0},{-1,0},{0,-1}};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0) ji++;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) dfs(i,j,0);
            }
        }
        return ans;
    }
    public void dfs(int x,int y,int t)
    {
     //  if(t==ji+1&&) {ans++;return;}
       if(x<0||y<0||x>=n||y>=m) return;
       if(t==ji+1&&grid[x][y]==2) {ans++;return;}
       if(grid[x][y]==-1||grid[x][y]==2) return;
       grid[x][y]=-1;
       for(int i=0;i<4;i++)
       {
           dfs(x+dir[i][0],y+dir[i][1],t+1);
       } 
       grid[x][y]=0;  
    }
}
```