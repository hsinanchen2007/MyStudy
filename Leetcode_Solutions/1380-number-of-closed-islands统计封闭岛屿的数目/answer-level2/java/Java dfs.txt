```java
class Solution {
    public int closedIsland(int[][] grid) {
        int ret = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 0) {
                    ret += dfs(grid, i, j);
                }
            }
        }
        return ret;
    }

    private int dfs(int[][] grid, int r, int c) {
        if (r < 0 || r >= grid.length || c < 0 || c >= grid[0].length) {
            return 0;
        }
        if (grid[r][c] == 1) {
            return 1;
        }
        grid[r][c] = 1;
        int[] vr = {0, 1, 0, -1};
        int[] vc = {1, 0, -1, 0};
        int ret = 1;
        for (int i = 0; i < 4; i++) {
            ret = Math.min(ret, dfs(grid, r + vr[i], c + vc[i]));
        }
        return ret;
    }
}
```