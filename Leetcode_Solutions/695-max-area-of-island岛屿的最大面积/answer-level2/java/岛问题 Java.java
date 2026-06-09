### 解题思路
无

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0){
            return 0;
        }
        int m = grid.length;
        int n = grid[0].length;
        int max = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1){
                    process(grid, i, j, m, n);
                    max = Math.max(max, res);
                    res = 0;
                }
            }
        }
        return max;
    }

    int res = 0;
    private void process(int[][] grid, int i, int j, int m, int n) {
        if (grid[i][j] == 1){
            res++;
            grid[i][j] = 2;
        }
        if (i - 1 >= 0 && grid[i-1][j] == 1){
            process(grid, i-1, j, m, n);
        }
        if (i + 1 < m && grid[i+1][j] == 1){
            process(grid, i+1, j, m, n);
        }
        if (j - 1 >= 0 && grid[i][j-1] == 1){
            process(grid, i, j-1, m, n);
        }
        if (j + 1 < n && grid[i][j+1] == 1){
            process(grid, i, j+1, m, n);
        }
    }
}
```