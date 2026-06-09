### 解题思路
遍历整个二维数组,当grid[i][j] = '1'时，DFS遍历其四周的点，如果时1的话继续DFS，直到遍历结束。

### 代码

```java
class Solution {
    public int numIslands(char[][] grid) {
        int count = 0;
        for(int i = 0;i<grid.length;i++) {
            for(int j = 0;j<grid[i].length;j++) {
                if(grid[i][j] == '1') {
                    dfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
    public void dfs(int i,int j,char[][] grid){
        if (i>=0 && i< grid.length && j>=0 && j<=grid[i].length) {
            grid[i][j] = '0';
            if(i+1 <= grid.length-1 && grid[i+1][j] == '1')
                dfs(i+1, j, grid);
            if(i-1 >= 0 && grid[i-1][j] == '1')
                dfs(i-1, j, grid);
            if(j+1 <= grid[i].length-1 && grid[i][j+1] == '1')
                dfs(i, j+1, grid);
            if(j-1 >= 0 && grid[i][j-1] == '1')
                dfs(i, j-1, grid);
        }
    }
}
```