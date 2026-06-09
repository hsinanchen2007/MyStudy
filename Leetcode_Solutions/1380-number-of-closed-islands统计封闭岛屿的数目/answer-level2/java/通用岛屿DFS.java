```
class Solution {
    private int[][] dirArr = new int[][]{{1,0},{0,1},{-1,0},{0,-1}};

    public int closedIsland(int[][] grid) {
        if (grid == null || grid.length < 1) {
            return 0;
        }
        int res = 0;
        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {
                if (grid[r][c] == 0) {
                    res += dfs(grid, r, c);
                }
            }
        }
        return res;
    }

    private int dfs(int[][] grid, int r, int c) {
        if (!inArea(grid, r, c)) {
            return 0;
        }
        int res = 1;
        if (grid[r][c] == 0) {
            grid[r][c] = 1;
            for (int[] dir : dirArr) {
                res = Math.min(res, dfs(grid, r + dir[0], c + dir[1]));
            }
        }
        return res;
    }

    private boolean inArea(int[][] grid, int r, int c) {
        return r >= 0 && r < grid.length && c >= 0 && c < grid[0].length;
    }
}
```
