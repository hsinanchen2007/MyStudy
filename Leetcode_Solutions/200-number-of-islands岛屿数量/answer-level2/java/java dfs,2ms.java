### 解题思路


### 代码

```java
class Solution {
    public int numIslands(char[][] grid) {//dfs
        if(grid.length==0)
        return 0;
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        int count = 0;
        for (int i=0; i<grid.length;i++)
          for(int j=0; j<grid[0].length ;j++)
          {
              if(visited[i][j]==false && grid[i][j] == '1')//记录开始了几次dfs,就是几个岛屿
               {
                   count++;
                   dfs(grid,i,j,visited);
               }
          }
          return count;
    }
    public void dfs(char[][] grid,int i,int j,boolean[][] visited)
    {
        visited[i][j]=true;
        if(i-1>=0 && grid[i-1][j]=='1' && visited[i-1][j]==false)
         dfs(grid,i-1,j,visited);
        if(j-1>=0 && grid[i][j-1]=='1' && visited[i][j-1]==false)
         dfs(grid,i,j-1,visited);
        if(i+1<grid.length && grid[i+1][j]=='1' && visited[i+1][j]==false)
         dfs(grid,i+1,j,visited);
        if(j+1<grid[0].length && grid[i][j+1]=='1' && visited[i][j+1]==false)
         dfs(grid,i,j+1,visited); 
    }
}
```