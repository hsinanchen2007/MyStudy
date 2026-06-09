### 解题思路
这题跟求岛屿的面积类似。
先求出所有的位置的正方体个数，而后每个位置的正方体的个数减一并乘以2，即`count += (grid[i][j] - 1) * 2`;，则是当前位置上下重叠部分的面积
而后在于其前后左右的求重叠部分，每次只求一个即可
最后通过`sum * 6 - count`即可得到三锥形体的表面积。

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        if(grid == null || grid.length == 0 || grid[0].length == 0) return 0;
        int sum = 0, count = 0;
        for(int i = 0; i < grid.length; i ++){
            for(int j = 0; j < grid[i].length; j ++){
                sum += grid[i][j];
                if(grid[i][j] > 0) {
                    count += (grid[i][j] - 1) * 2;
                    if(i - 1 >= 0 && grid[i - 1][j] > 0) count += Math.min(grid[i][j], grid[i - 1][j]);
                    if(i + 1 < grid.length && grid[i + 1][j] > 0) count += Math.min(grid[i][j], grid[i + 1][j]);
                    if(j - 1 >= 0 && grid[i][j - 1] > 0) count += Math.min(grid[i][j], grid[i][j - 1]);
                    if(j + 1 < grid[i].length && grid[i][j + 1] > 0) count += Math.min(grid[i][j], grid[i][j + 1]);
                }
            }
        }
        return sum * 6 - count;
    }
}
```