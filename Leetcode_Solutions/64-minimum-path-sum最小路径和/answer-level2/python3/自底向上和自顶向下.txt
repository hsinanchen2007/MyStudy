## 思路:

与[62. 不同路径](https://leetcode-cn.com/problems/unique-paths/),[63. 不同路径 II](https://leetcode-cn.com/problems/unique-paths-ii/)是一类的题型.

动态规划,用`dp[i][j]`表示到`i,j`的最小路径和.

动态方程: `dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]`

注意这里的第一行,和第一列要单独考虑,

还有可以直接在`grid`上操作,优化空间!

再附上自顶向下动态规划, 大家可以附上 `Java` 代码吗?

## 代码:

自底向上

```python [1]
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid: return 0
        row = len(grid)
        col = len(grid[0])
        dp = [[0]*col for _ in range(row)]
        dp[0][0] = grid[0][0]
        # 第一行
        for j in range(1, col):
            dp[0][j] = dp[0][j-1] + grid[0][j]
        # 第一列
        for i in range(1, row):
            dp[i][0] = dp[i-1][0] + grid[i][0]
        
        for i in range(1, row):
            for j in range(1, col):
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
        return dp[-1][-1]
```



```java [1]
class Solution {
    public int minPathSum(int[][] grid) {
        if (grid == null) return 0;
        int row = grid.length;
        int col = grid[0].length;
        int[][] dp = new int[row][col];
        dp[0][0] = grid[0][0];
        // 第一行
        for (int j = 1; j < col; j++) dp[0][j] = dp[0][j - 1] + grid[0][j];
        // 第一列
        for (int i = 1; i < row; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[row - 1][col - 1];
    }
}
```



自顶向下

```python [2]
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        import functools
        if not grid: return 0
        row = len(grid)
        col = len(grid[0])
        @functools.lru_cache(None)
        def helper(i,j):
            if i == row - 1 and j == col - 1:
                return grid[i][j]
            if i >= row or j >= col:
                return float("inf")
            tmp = 0
            tmp += grid[i][j] + min(helper(i, j+1), helper(i+1, j))
            return tmp
        return helper(0, 0)
```

