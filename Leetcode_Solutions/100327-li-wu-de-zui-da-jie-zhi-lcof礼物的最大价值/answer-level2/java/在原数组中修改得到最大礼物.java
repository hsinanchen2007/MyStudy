### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxValue(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        // 第一行累加
        for (int i = 1; i < n; ++i) {
            grid[0][i] += grid[0][i - 1];
        }
        // 第一列累加
        for (int j = 1; j < m; ++j) {
            grid[j][0] += grid[j - 1][0];
        }
        // 每一项都加上 它的上方或者左边的最大值
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] += Math.max(grid[i-1][j], grid[i][j-1]);
            }
        }
        // 最右下角是最大礼物
        return grid[m-1][n-1];
    }
}
```