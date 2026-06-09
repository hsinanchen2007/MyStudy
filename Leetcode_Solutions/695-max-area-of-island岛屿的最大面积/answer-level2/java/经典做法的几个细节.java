### 解题思路
1.注意行和列，一步小心会写错
2.注意结束递归的五个条件，一个不能少。

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }
        int res = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1) {
                    res = Math.max(res, dfs(grid, i, j));
                }
            }
        }
        return res;
    }

    private int dfs(int[][] grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.length || j >= grid[i].length || grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;
        int num = 1;
        num += dfs(grid, i + 1, j);
        num += dfs(grid, i, j + 1);
        num += dfs(grid, i - 1, j);
        num += dfs(grid, i, j - 1);
        return num;
    }
}
```