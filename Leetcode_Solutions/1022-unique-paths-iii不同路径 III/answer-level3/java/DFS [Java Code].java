### 解题思路
普通的dfs 深搜， 感觉不像是个hard难度的题

### 代码

```java
class Solution {

    private int count = 0;
    private boolean[][] visited;
    private int[][] dir = new int[][]{
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    
    public int uniquePathsIII(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }
        int numZero = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 0) {
                    numZero++;
                }
            }
        }
        visited = new boolean[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, 0, numZero);
                    return count;
                }
            }
        }
        return 0;
    }

    

    private void dfs(int[][] grid, int i, int j, int step, int numZero) {
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] == -1) {
            return;
        }
        if (grid[i][j] == 2) {
            if (step - 1 == numZero) {
                count++;
            }
            return;
        }

        if (!visited[i][j]) {
            visited[i][j] = true;
            for (int[] d : dir) {
                int x = i + d[0];
                int y = j + d[1];
                dfs(grid, x, y, step + 1, numZero);
            }
            visited[i][j] = false;
        }
    }
}
```