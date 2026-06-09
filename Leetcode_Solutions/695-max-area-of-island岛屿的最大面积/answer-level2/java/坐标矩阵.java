### 解题思路
1、坐标矩阵，上下左右寻找
2、走过的1改成0

### 代码

```java
class Solution {
    private int colum;
    private int row;
    private int[] X = {0, 0, 1, -1};
    private int[] Y = {1, -1, 0, 0};

    public int maxAreaOfIsland(int[][] grid) {
        colum = grid.length;
        row = grid[0].length;
        int max = 0;
        for (int i = 0; i < colum; i++) {
            for (int j = 0; j < row; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                grid[i][j] = 0;
                int one = 1;
                one += searchOne(grid, i, j);
                max = Math.max(max, one);
            }
        }
        return max;
    }
    private int searchOne(int[][] grid, int x, int y) {
        int count = 0;
        for (int i = 0; i < X.length; i++) {
            int newX = x + X[i];
            int newY = y + Y[i];
            if (isValid(newX, newY)) {
                if (grid[newX][newY] == 1) {
                    grid[newX][newY] = 0;
                    count++;
                    count += searchOne(grid, newX, newY);
                }
            }
        }
        return count;
    }
    private boolean isValid(int x, int y) {
        return (x >= 0 && x < colum && y >= 0 && y < row) ? true : false;
    }
}
```