### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
     private int[][] directions = {{0,-1},{-1,0},{0,1},{1,0}};
    private int[][] paths = {{0,2},{1,3},{0,3},{2,3},{0,1},{1,2}};
    private boolean[][] visited = null;
    private boolean[][] dp = null;
    int m=0,n=0;
    public boolean hasValidPath(int[][] grid) {
        if(grid==null||grid.length<1||grid[0].length<1) return false;
        m=grid.length;
        n=grid[0].length;
        visited = new boolean[m][n];
        dp = new boolean[m][n];
        dfsGrid(grid,0,0,paths[grid[0][0]-1][0]);
        return dp[m-1][n-1];
    }
    private boolean dfsGrid(int[][] grid,int i,int j,int from){
        if(i==m-1&&j==n-1){
            dp[i][j] = true;
            return true;
        }
        if(i<0||i==m||j<0||j==n){
            return false;
        }
        if(visited[i][j]) return false;
        int[] curPath = paths[grid[i][j]-1];
        int to  = from==curPath[0]?curPath[1]:curPath[0];
        int[] direction = directions[to];
        int nextI = i+direction[0],nextJ = j+direction[1];
        if(nextI<0||nextI==m||nextJ<0||nextJ==n){
            return false;
        }
        int[] nextPath = paths[grid[nextI][nextJ] -1];
        if((to+nextPath[0])%2==0 && to!=nextPath[0]){
            visited[i][j] = true;
            dp[i][j] = dfsGrid(grid,nextI,nextJ,nextPath[0]);
        } else if((to+nextPath[1])%2==0 && to!=nextPath[1]){
            visited[i][j] = true;
            dp[i][j] = dfsGrid(grid,nextI,nextJ,nextPath[1]);
        }else {
            visited[i][j] = true;
            dp[i][j] = false;
            return false;
        }
        return dp[i][j];
    }
}
```