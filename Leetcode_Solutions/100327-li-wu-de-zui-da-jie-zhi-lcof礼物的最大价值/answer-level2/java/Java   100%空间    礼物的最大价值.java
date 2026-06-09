### 解题思路
result存储最终的结果！！！

### 代码

```java
class Solution {
    public int maxValue(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] result = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            int left = 0, up = 0;
            for (int j = 0; j < cols; j++) {
                if (i > 0) {
                    up = result[i - 1][j]; // 一定是拿result的数据
                }
                if (j > 0) {
                    left = result[i][j - 1]; // 一定是拿result的数据
                }
                result[i][j] = Math.max(left, up) + grid[i][j];
            }
        }

        return result[rows - 1][cols - 1];
    }
}
```