### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int islandPerimeter(int[][] grid) {
        int back = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1) {
                    back = back + 4 - isEage(grid, i + 1, j) - isEage(grid, i - 1, j) - isEage(grid, i, j + 1)
                        - isEage(grid, i, j - 1);
                }
            }
        }
        return back;
    }

    public int isEage(int[][] grid, int x, int y) {
        if (x >= 0 && x < grid.length && y >= 0 && y < grid[x].length) {
            return grid[x][y];
        }
        return 0;
    }
}
```