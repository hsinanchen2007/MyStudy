### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {

    private int res;

    public int maxAreaOfIsland(int[][] grid) {
        res = 0;
        boolean[][] status = new boolean[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1 && !status[i][j]) {
                    res = Math.max(dfs(grid, status, j, i), res);
                }
            }
        }
        return res;
    }

    private int dfs(int [][]grid, boolean [][]status, int col, int row) {
        if (legal(grid, col, row) && grid[row][col] == 1 && !status[row][col]) {
            status[row][col] = true;
            int count = 1;
            count += dfs(grid, status, col, row - 1);
            count += dfs(grid, status, col, row + 1);
            count += dfs(grid, status, col - 1, row);
            count += dfs(grid, status, col + 1, row);
            return count;
        } else {
            return 0;
        }
    }

    private boolean legal(int [][]grid, int col, int row) {
        return row >= 0 && row < grid.length && col >= 0 && col < grid[0].length;
    }
}
```