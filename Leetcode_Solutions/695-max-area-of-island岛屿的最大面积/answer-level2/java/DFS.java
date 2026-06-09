### 解题思路
很有意思的题目，一开始我倒是没想到要用深搜，因为不是一个树形结构，但仔细想想刚好就是一个向四个方向查找的过程

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int res = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    res = Math.max(res, dfs(i, j, grid));
                }
            }
        }
        return res;
    }

    int dfs(int i, int j, int[][] grid) {
        int ret = 1;
        if (i == -1 || j == -1 || i == grid.length || j == grid[0].length || grid[i][j] == 0 || grid[i][j] == 2) return 0;
        grid[i][j] = 2;
        ret += dfs(i + 1, j, grid);
        ret += dfs(i - 1, j, grid);
        ret += dfs(i, j - 1, grid);
        ret += dfs(i, j + 1, grid);
        return ret;
    }
}
```