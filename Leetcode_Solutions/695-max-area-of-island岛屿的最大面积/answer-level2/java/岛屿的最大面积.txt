### 解题思路
题目四个方向遍历，唯一需要注意的就是如何避免重复访问，这里将每一个已经访问过的节点标为“2”，来区分岛屿的“1"。

### 代码

```java
class Solution {
    int max = 0;
    public int helper(int[][] grid, int r, int c) {
        if (r < 0 || r >= grid.length || c < 0 || c >= grid[0].length) return 0;
        if (grid[r][c] == 1) {
            grid[r][c] = 2;
            int a = helper(grid, r, c + 1);
            int b = helper(grid, r, c - 1);
            int d = helper(grid, r + 1, c);
            int e = helper(grid, r - 1, c);
            int area = a + b + d + e + 1;
            max = Math.max(max, area);
            return area;
        }
        return 0;
    }
    public int maxAreaOfIsland(int[][] grid) {
        if (grid == null || grid.length == 0) return 0;
        int row = grid.length;
        int col = grid[0].length;
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                helper(grid, r, c);
            }
        }
        return max;
    }
}
```