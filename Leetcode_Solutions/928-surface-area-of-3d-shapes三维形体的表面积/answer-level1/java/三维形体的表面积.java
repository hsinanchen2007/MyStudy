### 解题思路
先求上下堆叠的标面积，然后在减去跟左和上边相邻的表面积，得出的就是最后面积。

### 代码

```java
class Solution {
    public int crossFaces(int a, int b) {
        return Math.min(a, b) * 2;
    }
    public int surfaceArea(int[][] grid) {
        if (grid.length == 0) return 0;
        int row = grid.length;
        int col = grid[0].length;
        int faces = 0;
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                int n = grid[r][c];
                if (n > 0) { faces += n * 4 + 2; 
                    if (c > 0) { faces -= crossFaces(n, grid[r][c - 1]); }
                    if (r > 0) { faces -= crossFaces(n, grid[r - 1][c]); }
                }
            }
        }
        return faces;
    }
}
```