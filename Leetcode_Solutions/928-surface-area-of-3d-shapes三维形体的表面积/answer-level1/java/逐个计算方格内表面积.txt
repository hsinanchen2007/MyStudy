### 解题思路
逐个计算每个方格内的正方体的表面积，然后累积。每个方格内表面积的计算，先计算孤立情况下的表面积，再根据四周的正方体高度，减去重叠的部分面积。

### 代码

```java
class Solution {
    private int[][] grid;
    public int surfaceArea(int[][] grid) {
        this.grid = grid;
        int area = 0;
        for (int i = 0; i < grid.length; i ++) {
            for (int j = 0; j < grid[i].length; j ++) {
                if (grid[i][j] != 0) {
                    area += singleArea(i, j);
                }
            }
        }
        return area;
    }

    private int singleArea(int i, int j) {
        int area = grid[i][j] * 4 + 2;
        if (i > 0) {
            area -= Math.min(grid[i - 1][j], grid[i][j]);
        }
        if (j > 0) {
            area -= Math.min(grid[i][j - 1], grid[i][j]);
        }
        if (i < grid.length - 1) {
            area -= Math.min(grid[i + 1][j], grid[i][j]);
        }
        if (j < grid[i].length - 1) {
            area -= Math.min(grid[i][j + 1], grid[i][j]);
        }
        return area;
    }
}
```