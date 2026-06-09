### 解题思路
设置visited数组，深度遍历思想。
与之前的机器人的活动范围思想一样。
主要是考虑越界，是否被访问，是否可访问；如果可访问则需要更新visited为true，避免下次访问，减少重复结果的次数。
一个有效结果的一个格子遍历过，其他格子作为起点进行遍历时结果与其一样，因为设置为已遍历，减少重复结果的处理。

### 代码

```java
class Solution {
    int rows = 0, cols = 0;
    int maxArea = 0;
    boolean[][] visited = null;
    public int maxAreaOfIsland(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }

        rows = grid.length;
        cols = grid[0].length;
        visited = new boolean[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int area = func(grid, i, j);
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }

        return maxArea;
    }

    private int func(int[][] grid, int i, int j) {
        if (i < 0 || j < 0 || i >= rows || j >= cols || visited[i][j] || grid[i][j] == 0) {
            return 0;
        }

        visited[i][j] = true;
        int count = 1;
        count += func(grid, i - 1, j) + func(grid, i + 1, j) + func(grid, i, j - 1) + func(grid, i, j + 1);
        return count;
    }
}
```