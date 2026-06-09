做完DFS题不久，所以这题的第一感觉也是DFS，速度就别指望了。

基本思路就是对于方格A每存在一个不为0相邻方格,方格A持有的边数就减1

执行用时 :19 ms, 在所有 Java 提交中击败了5.36% 的用户
内存消耗 :42.9 MB, 在所有 Java 提交中击败了100.00%的用户

```
// 定义a，b是为了方便以及避免减掉4条边后为0
    private final int a = 5;
    private final int b = a - 4;
    public int islandPerimeter(int[][] grid) {
        if (grid == null || grid.length == 0) return 0;
        int row = grid.length, column = grid[0].length;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) if (grid[i][j] == 1) grid[i][j] = a;
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) if (grid[i][j] == a) islandPerimeterHelper(grid, i, j);
        }
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) if (grid[i][j] != 0) ans += grid[i][j] - b;
        }
        return ans;
    }

    int[] dr = new int[]{-1, 0, 1, 0}, dc = new int[]{0, -1, 0, 1};
    public void islandPerimeterHelper(int[][] grid, int r, int c) {
        for (int k = 0; k < dr.length; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nc < 0 || nr < 0 || nr >= grid.length || nc >= grid[0].length) continue;
            // grid[nr][nc] > 0 说明 grid[r][c]有不为0的邻边
            if (grid[nr][nc] > 0) grid[r][c] = grid[r][c] - 1;
            if (grid[nr][nc] == a) {
                islandPerimeterHelper(grid, nr, nc);
            }
        }
    }
```
