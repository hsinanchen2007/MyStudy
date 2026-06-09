### 解题思路
最小路径和，利用动态规划思想，dp[i][j]为到达(i，j)位置时的最优解（最小值），确定边界：因每次只能向下或者向右移动一步，故第零列和第零行的dp[0][j],dp[i][0]的值只与第0列、第0行有关，初始化dp[0][0]=grid[0][0]，迭代返回右下角的值即可

### 代码

```python3
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [[0 for i in range(n)] for j in range(m)]
        dp[0][0] = grid[0][0]
        for i in range(1,m):
            dp[i][0] = dp[i-1][0] + grid[i][0]
        for j in range(1,n):
            dp[0][j] = dp[0][j-1] + grid[0][j]
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j]= min(dp[i-1][j],dp[i][j-1]) + grid[i][j]
        return dp[-1][-1]

```