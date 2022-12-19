不知道为什么时间在 98% 到 87% 之间徘徊～～～
```java
class Solution {
    // 每次只能向下或者向右移动一步，我们假设：
    // dis[i][j] 为最小值；
    public int minPathSum(int[][] grid) {
        int R = grid.length;
        int C = grid[0].length;
        int[] sum = new int[C]; // 上一行的数据；
        sum[0] = grid[0][0];
        for (int j = 1; j < C; ++j) {
            // 累加下即可；
            sum[j] = sum[j - 1] + grid[0][j];
        }
        for (int i = 1; i < R; ++i) {
            for (int j = 0; j < C; ++j) { // 这里要从 0 开始
                // int pre = sum[j];
                if (j == 0) {
                    sum[j] = grid[i][j] + sum[j];
                } else {
                    sum[j] = grid[i][j] + Math.min(sum[j - 1], sum[j]);
                }
                // sum[j] = grid[i][j] + Math.min(pre, sum[j]);
            }
        }
        return sum[C - 1];
    }
}
```
