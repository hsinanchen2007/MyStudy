# 代码
```java
class Solution {
    private LinkedList<List<Integer>> res = new LinkedList<>();
    private int global_row, global_col;
    private int[][] global_grid;
    private boolean found = false;

    public List<List<Integer>> pathWithObstacles(int[][] obstacleGrid) {
        global_row = obstacleGrid.length;
        global_col = obstacleGrid[0].length;
        if (obstacleGrid[0][0] > 0 || obstacleGrid[global_row - 1][global_col - 1] > 0) return res;
        global_grid = obstacleGrid;
        res.addLast(Arrays.asList(0, 0));
        dfs(0, 0);
        return found ? res : new LinkedList<>();
    }

    private void dfs(int row, int col) {
        if (row == global_row - 1 && col == global_col - 1) {
            found = true;
            return;
        }
        if (col + 1 < global_col && global_grid[row][col + 1] == 0) {
            res.addLast(Arrays.asList(row, col + 1));
            dfs(row, col + 1);
            if (found) return;
            res.removeLast();
        }
        if (row + 1 < global_row && global_grid[row + 1][col] == 0) {
            res.addLast(Arrays.asList(row + 1, col));
            dfs(row + 1, col);
            if (found) return;
            res.removeLast();
        }
    }
}
```
