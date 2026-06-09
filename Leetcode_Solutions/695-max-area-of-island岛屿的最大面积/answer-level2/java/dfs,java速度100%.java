### 解题思路
参考感染岛屿思路，每次遇见1，dfs，将搜索到的点感染(设置为2)

### 代码

```java
class Solution {
    int count = 0;
    public int maxAreaOfIsland(int[][] grid) {
        int max = 0, m = grid.length, n = grid[0].length, tmp = 0;
        if(m == 0) return max;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j);
                    max = Math.max(max, count);
                    count = 0;
                }
            }
        }
        return max;
    }
    public void dfs(int[][] grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] != 1) return;
        count++;
        grid[i][j] = 2;
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1); 
    }
}
```