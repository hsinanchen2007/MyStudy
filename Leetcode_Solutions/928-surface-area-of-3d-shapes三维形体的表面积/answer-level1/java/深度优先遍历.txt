### 解题思路
常规的深度优先遍历，多了一步计算表面积

### 代码

```java
class Solution {
    private int rows, cols, area;
    private int[][] data;
    private boolean[][] visited;

    public int surfaceArea(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }

        data = grid;
        rows = grid.length;
        cols = grid[0].length;
        visited = new boolean[rows][cols];

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] > 0 && !visited[row][col]) {
                    dfs(row, col);
                }
            }
        }
        return area;
    }

    private int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    private void dfs(int row, int col) {
        if (row < 0 || col < 0 || row >= rows || col >= rows
                || visited[row][col] || data[row][col] <= 0) {
            return;
        }

        visited[row][col] = true;
        area += countArea(row, col);
        for (int[] direction : directions) {
            dfs(row + direction[0], col + direction[1]);
        }
    }

    private int countArea(int row, int col) {
        // 1-6 2-10 3-3*6-2*2
        int num = data[row][col];
        int size = num * 6 - (num - 1) * 2;

        int around = 0;
        for (int[] direction : directions) {
            int newRow = row + direction[0], newCol = col + direction[1];
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && data[newRow][newCol] > 0) {
                around += Math.min(num, data[newRow][newCol]);
            }
        }
        return size - around;
    }

}
```