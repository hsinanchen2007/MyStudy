**解题思路:**
1. 假如网格上有大于1个的方块。那么这个网格上的表面积至少为2 -> **顶部 和 底部**
2. 接下来就需要考虑该网格上方块的**四个面有哪些被挡住了**？挡住了多少？
3. 以坐标（i,j）左边的面为例：
- 如果j为0的话，也就是左边没有可以挡住它的方块。那么（i,j）上有几个方块，左边的表面积就是多少。
- 如果j大于0，但是（i,j-1）上方块的数量大于等于（i,j）上的方块数，那么也就是说左边完全被挡住了，左边的表面积为0。
- 如果j大于0，但是（i,j-1）上方块的数量小于（i,j）上的方块数，那么（i,j）上比（i,j-1）多几个方块，它左边的表面积就是几。


**代码：**
```
class Solution {
    public int surfaceArea(int[][] grid) {
        int surface = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                surface += getSurface(grid, i, j);
            }
        }

        return surface;
    }

    private int getSurface(int[][] grid, int i, int j) {
        if (grid[i][j] == 0) {
            return 0;
        }

        int surface = 2;

        // 下面的表面积
        if (i + 1 < grid.length) {
            if (grid[i + 1][j] < grid[i][j]) {
                surface += grid[i][j] - grid[i + 1][j];
            }
        } else {
            surface += grid[i][j];
        }

        // 上面的表面积
        if (i - 1 >= 0) {
            if (grid[i - 1][j] < grid[i][j]) {
                surface += grid[i][j] - grid[i - 1][j];
            }
        } else {
            surface += grid[i][j];
        }

        // 左面的表面积
        if (j - 1 >= 0) {
            if (grid[i][j - 1] < grid[i][j]) {
                surface += grid[i][j] - grid[i][j - 1];
            }
        } else {
            surface += grid[i][j];
        }

        // 右面的表面积
        if (j + 1 < grid[i].length) {
            if (grid[i][j + 1] < grid[i][j]) {
                surface += grid[i][j] - grid[i][j + 1];
            }
        } else {
            surface += grid[i][j];
        }

        return surface;
    }
}
```
