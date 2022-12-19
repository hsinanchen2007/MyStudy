```
class Solution {
    private int[][] dirArr = new int[][]{{1,0},{0,1},{-1,0},{0,-1}};

    public int maxAreaOfIsland(int[][] grid) {
        if (grid == null || grid.length < 1) {
            return 0;
        }
        int max = 0;
        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {
                if (grid[r][c] == 1) {
                    int area = dfs(grid, r, c);
                    max = Math.max(max, area);
                }
            }
        }
        return max;
    }

    private int dfs(int[][] grid, int r, int c) {
        int res = 0;
        if (inArea(grid, r, c) && grid[r][c] == 1) {
            grid[r][c] = 0;
            res++;
            for (int[] dir : dirArr) {
                res += dfs(grid, r + dir[0], c + dir[1]);
            }
        }
        return res;
    }

    private boolean inArea(int[][] grid, int r, int c) {
        return r >=0 && r < grid.length && c >=0 && c < grid[0].length;
    }
}
```
