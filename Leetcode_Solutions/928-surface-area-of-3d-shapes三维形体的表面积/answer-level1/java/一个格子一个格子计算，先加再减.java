### 解题思路
一个格子一个格子计算，如果方块数为0，进入下一次循环；否则，总表面积先加上当前方块的表面积，再减去其左侧和上侧的重叠部分。

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0)
            return 0;
        
        int s = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 0)    continue;
                s += 2 + grid[i][j] * 4;
                if (i - 1 >= 0) {
                    s -= 2 * Math.min(grid[i][j], grid[i-1][j]);
                }
                if (j - 1 >= 0) {
                    s -= 2 * Math.min(grid[i][j], grid[i][j-1]);
                }
            }
        }
        return s;
    }
}
```