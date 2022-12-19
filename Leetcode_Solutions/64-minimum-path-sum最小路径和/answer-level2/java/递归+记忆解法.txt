### 解题思路
采用递归解法，然后加入记忆

### 代码

```java
class Solution {
    private int m;
    private int n;
    private int[][] grid;
    private Integer[][] memo;

    public int minPathSum(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }
        this.m = grid.length;
        this.n = grid[0].length;
        this.grid = grid;
        this.memo = new Integer[m][n];
        memo[m - 1][n - 1] = grid[m - 1][n - 1];

        return path(0, 0);
    }

    private int path(int row, int column) {
        if (row >= m || column >= n) {
            return Integer.MAX_VALUE;
        }

        if (memo[row][column] != null) {
            return memo[row][column];
        }

        int left = path(row, column + 1);
        int down = path(row + 1, column);
        int result = Math.min(left, down) + grid[row][column];
        memo[row][column] = result;
        return result;
    }
}
```