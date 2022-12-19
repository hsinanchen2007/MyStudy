### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int max = 0;
        if (null == grid || grid.length == 0)
            return 0;

        for (int i=0; i<grid.length; ++i) {
            for (int j=0; j<grid[0].length; ++j) {
                max = Math.max(max, dps(grid, i, j));
            }
        }
        return max;
    }

    private int dps(int[][] grid, int x, int y) {
        if (x < 0 || x >= grid.length)
            return 0;
        if (y < 0 || y >= grid[0].length)
            return 0;

        if (0 == grid[x][y])
            return 0;
        grid[x][y] = 0;
        return 1+dps(grid,x-1,y)+dps(grid,x+1,y)+dps(grid,x,y-1)+dps(grid,x,y+1);
    }
}
```