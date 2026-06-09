
### 代码

```java
class Solution {
    public int maxValue(int[][] grid) {

        if (grid == null || grid.length == 0) return 0;

        int row = grid.length;
        int col = grid[0].length;

        // 初始化第一行、第一列
        for (int i = 1; i < col; i++) grid[0][i] += grid[0][i - 1];
        for (int i = 1; i < row; i++) grid[i][0] += grid[i - 1][0];

        //自顶向下 当前位置（礼物最大值） = 上一行 和 前一列 的最大值 + 当前礼物值
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                grid[i][j] += Math.max(grid[i - 1][j],grid[i][j - 1]);
            }
        }

        return grid[row - 1][col - 1];
    }
}
```
时间复杂度： O（N^2）
空间复杂度： O (1)

执行用时 :2 ms, 在所有 Java 提交中击败了97.86% 的用户
内存消耗 :42.2 MB, 在所有 Java 提交中击败了100.00%的用户