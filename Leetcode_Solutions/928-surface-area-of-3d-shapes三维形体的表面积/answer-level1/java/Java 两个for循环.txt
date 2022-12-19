### 解题思路
一个长方体的表面积是4 * 个数 + 2

然后要减去和其他长方体重叠的部分

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int res = 0;
        for (int i = 0; i < grid.length; i ++) {
            for (int j = 0; j < grid[i].length; j ++) {
                if (grid[i][j] > 0) res += 4 * grid[i][j] + 2;
                if (i > 0) res -= Math.min(grid[i][j], grid[i - 1][j]) * 2;
                if (j > 0) res -= Math.min(grid[i][j], grid[i ][j - 1]) * 2;
            }
        }
        return res;
    }
}
```