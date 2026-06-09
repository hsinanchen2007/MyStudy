### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        int res = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1 && visited[i][j] == false) {
                    int count = dfs(grid, i, j, visited);
                    res = Math.max(res, count);
                }
            }
        }
        return res;
    }

    private int dfs(int[][] grid, int i, int j, boolean[][] visited) {
        if (grid[i][j] == 0 || visited[i][j] == true) {
            return 0;
        }
        visited[i][j] = true;
        int count = 1;
        // up
        if (i > 0) {
            count += dfs(grid, i - 1, j, visited);
        }

        // down
        if (i < grid.length - 1) {
            count += dfs(grid, i + 1, j, visited);
        }

        // left
        if (j > 0 ) {
            count += dfs(grid, i, j - 1, visited);
        }

        // right
        if (j < grid[0].length - 1) {
            count += dfs(grid, i, j + 1, visited);
        }

        return count;
    }
}
```