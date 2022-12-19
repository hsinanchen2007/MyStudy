### 解题思路

DFS写出来就发现重复计算了，没运行就放弃。想着加个记忆化搜索的步骤，发现似乎有点难搞，还是动态规划简单。

经典动态规划，状态dp[i][j]为到从左上角到(i,j)为止的最小路径，转移方程也简单，就是(i - 1, j)和(i, j - 1)中较小的一个加上该店的值。

### 代码

```python3
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        row = len(grid)
        if not row:
            return 0
        col = len(grid[0])
        if not col:
            return 0
        
        # # dfs应该会超时
        # self.res = float('inf')
        # def dfs(i, j, cur_sum):
        #     if i == row - 1 and j == col - 1:
        #         cur_sum += grid[i][j]
        #         self.res = min(self.res, cur_sum)
        #         return
        #     if cur_sum + grid[i][j] > self.res:
        #         return 
        #     if i < row - 1:
        #         dfs(i + 1, j, cur_sum + grid[i][j])
        #     if j < col - 1:
        #         dfs(i, j + 1, cur_sum + grid[i][j])
        # dfs(0, 0, 0)

        dp = [[0 for _ in range(col)] for _ in range(row)]
        dp[0][0] = grid[0][0]
        for i in range(1, row):
            dp[i][0] = dp[i - 1][0] + grid[i][0]
        for i in range(1, col):
            dp[0][i] = dp[0][i - 1] + grid[0][i]
        
        for i in range(1, row):
            for j in range(1, col):
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
        
        return dp[row - 1][col - 1]
        
```