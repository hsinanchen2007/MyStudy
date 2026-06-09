### 解题思路
DFS+剪枝

### 代码

```java
class Solution {
   public int maxAreaOfIsland(int[][] grid) {
        int max = 0;
        int tmp = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    tmp = maxAreaOfIslandCore(grid, i, j);
                    max = max > tmp ? max : tmp;
                }
            }
        }
        return max;
    }

    public int maxAreaOfIslandCore(int[][] grid, int i, int j) {
       if ((i >= 0 && i < grid.length) && (j >= 0 && j < grid[0].length) && grid[i][j] == 1) {
            grid[i][j] = 0;
            int left = maxAreaOfIslandCore(grid, i, j - 1);
            int right = maxAreaOfIslandCore(grid, i, j + 1);
            int on = maxAreaOfIslandCore(grid, i + 1, j);
            int low = maxAreaOfIslandCore(grid, i - 1, j);
            return left + right + on + low + 1;
        } else return 0;
    }
}
```