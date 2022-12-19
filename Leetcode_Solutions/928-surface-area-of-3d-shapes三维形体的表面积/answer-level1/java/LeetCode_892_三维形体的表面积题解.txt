### 解题思路

首先计算i,j位置上的表面积（area = 6n - 2(n-1)），之后鉴权行列位置上重叠的面积即可。

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int res = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                // 计算i,j位置上立方体的表面积
                res += grid[i][j] * 6 - Math.max((grid[i][j] - 1), 0) * 2;
                if (j > 0) // 计算列上的重叠面积
                    res -= Math.min(grid[i][j], grid[i][j - 1]) * 2;
                if (i > 0) // 计算行上的重叠面积
                    res -= Math.min(grid[i][j], grid[i - 1][j]) * 2;
            }
        }
        return res;
    }
}
```