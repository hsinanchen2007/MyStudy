## 原始动态规划
### 解体思路
- 状态方程
    - dp[i][j] 表示 i*j 的网格左上角到右下角的最小路径
    - 每个位置都只有两种选择：向下或向右
    - dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
- 初始化
    - dp[0][0] = grid[0][0]
    - dp[0][j] = dp[0][j-1] + grid[0][j]
    - dp[i][0] = dp[i-1][0] + grid[i][0]

### 代码

```python3
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        '''
        思路：
            动态规划
                dp[i][j] 表示 i*j 的网格左上角到右下角的最小路径
                每个位置都只有两种选择：向下或向右
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
            初始化：
                dp[0][0] = grid[0][0]
                dp[0][j] = dp[0][j-1] + grid[0][j]
                dp[i][0] = dp[i-1][0] + grid[i][0]
        '''
        m, n = len(grid), len(grid[0])
        dp = [[0]*n for i in range(m)]
        dp[0][0] = grid[0][0]
        for i in range(1, m):
            dp[i][0] = dp[i-1][0] + grid[i][0]
        for j in range(1, n):
            dp[0][j] = dp[0][j-1] + grid[0][j]
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
        return dp[m-1][n-1]

```
## 空间优化：滚动数组
### 解题思路
- 只用到下边和右边的一个，而且右边只被使用一次
- 所以只需保持一列状态值 dp 即可，一列一列计算
- 假设 j 为当前计算的列数，则状态转移为
    - dp[i] = grid[i][j]+min(dp[i-1],dp[i])
    - dp[i-1] 对应原来的下方状态，dp[i]对应右边状态
### 代码
```python
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        '''
        思路：
            动态规划
                dp[i][j] 表示 i*j 的网格左上角到右下角的最小路径
                每个位置都只有两种选择：向下或向右
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
            初始化：
                dp[0][0] = grid[0][0]
                dp[0][j] = dp[0][j-1] + grid[0][j]
                dp[i][0] = dp[i-1][0] + grid[i][0]
            空间优化：滚动数组
                只用到下边和右边的一个，而且右边只被使用一次
                所以只需保持一列状态值 dp 即可，一列一列计算
                假设 j 为当前计算的列数，则状态转移为
                    dp[i] = grid[i][j]+min(dp[i-1],dp[i])
                    dp[i-1] 对应原来的下方状态，dp[i]对应右边状态
        '''
        m, n = len(grid), len(grid[0])
        dp = [0] * m
        dp[0] = grid[0][0]
        for i in range(1, m):
            dp[i] = dp[i-1] + grid[i][0]
        
        for j in range(1, n):
            dp[0] = dp[0] + grid[0][j]
            for i in range(1, m):
                dp[i] = grid[i][j] + min(dp[i-1], dp[i])
        return dp[m-1]
```