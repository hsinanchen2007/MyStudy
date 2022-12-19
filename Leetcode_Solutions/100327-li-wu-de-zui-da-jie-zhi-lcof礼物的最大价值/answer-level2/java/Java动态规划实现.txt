动态规划实现，先进行dp数组初始化，然后根据状态转移方程，迭代出最佳解。
```
OPT(i, j) = max(OPT(i - 1, j), OPT(i, j - 1)) + grid[i][j];
BASECASE:
case1:OPT(0, 0) = grid[0][0](i == 0 && j == 0);
case2:OPT(0, j) = OPT(0, j - 1) + grid[0][j](i == 0);
case3:OPT(i, 0) = OPT(i - 1, 0) + grid[i][0](j == 0);
```

```
class Solution {
    public int maxValue(int[][] grid) {
        int row = grid.length, col = grid[0].length;
        int[][] dp = new int[row][col];
        dp[0][0] = grid[0][0];
        //初始化dp数组
        for (int i = 1; i < row; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < col; ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                //可以选择是左边的还是上边的走到这一步
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        
        return dp[row - 1][col - 1];
    }
}
```
其实这道题可以对原数组进行修改，不需要新建一个dp数组，节省空间。
```
class Solution {
    public int maxValue(int[][] grid) {
        int row = grid.length, col = grid[0].length;
        for (int i = 1; i < row; ++i) {
            grid[i][0] += grid[i - 1][0];
        }
        //初始化数组
        for (int j = 1; j < col; ++j) {
            grid[0][j] += grid[0][j - 1];
        }
        
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                //可以选择是左边的还是上边的走到这一步
                grid[i][j] += Math.max(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[row - 1][col - 1];
    }
}
```
