### 解题思路
暴力搜

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        if (grid.length == 0 || grid[0].length == 0) {
            return 0;
        }
        int max = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    max = Math.max(max, fun(i, j, grid));
                }
            }
        }

        return max;
    }

    public int fun(int x, int y, int[][] grid) {
        grid[x][y] = 0;
        int area = 1;

        //上下左右
        if (x > 0 && grid[x - 1][y] == 1) {
            area += fun(x - 1, y, grid);
        }
        if (x < grid.length - 1 && grid[x + 1][y] == 1) {
            area += fun(x + 1, y, grid);
        }
        if (y > 0 && grid[x][y - 1] == 1) {
            area += fun(x, y - 1, grid);
        }
        if (y < grid[0].length - 1 && grid[x][y + 1] == 1) {
            area += fun(x, y + 1, grid);
        }

        return area;
    }
}
```