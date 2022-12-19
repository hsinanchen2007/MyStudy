### 解题思路
深度优先，看注释。

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int max = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (1 == grid[i][j]) {
                    max = Math.max(max, dfs(i, j, grid));
                }
            }
        }

        return max;
    }

    private int dfs(int i, int j, int[][] grid) {
        if (i < 0 || j < 0 || i >= grid.length || j >= grid[i].length ||  0 == grid[i][j]) {//如果不是岛屿则直接返回
            return 0;
        }
        int num = 1;
        grid[i][j] = 0;//修改为0，以防止重复计算
        num += dfs(i - 1, j, grid);
        num += dfs(i + 1, j, grid);
        num += dfs(i, j - 1, grid);
        num += dfs(i, j + 1, grid);

        return num;
    }
}
```