### 解题思路
此处撰写解题思路
和之前找有多少条路径不同，要找到最小的路径，逆序动态查找，将最后一个动态数组元素设置为grid[-1][-1],
最后一行和最后一列的元素的最小路径等于当前grid[i][-1]+dp[j+1]
再从倒数第二行和第二列开始计算  dp[i][j] = grid[i][j] + min(dp[i][j+1], dp[i+1][j])
### 代码

```python3
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        #逆向动态规划
        m = len(grid); n = len(grid[0])
        dp = [[0]*n for _ in range(m)]
        dp[-1][-1] = grid[-1][-1]
        for i in range(m-2,-1,-1):
            dp[i][-1] = grid[i][-1] + dp[i+1][-1]
        for j in range(n-2,-1,-1):
            dp[-1][j] += grid[-1][j] + dp[-1][j+1]
        for i in range(m-2,-1,-1):
            for j in range(n-2,-1,-1):
                dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1])

        return dp[0][0]
#一维数组解法
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        #逆向动态规划, 一维数组  数组的最右方的最小距离等于当前元素加上下方的距离
        m = len(grid); n = len(grid[0])
        dp = [0] * n
        for i in range(m-1,-1,-1):
            for j in range(n-1,-1,-1):
                if i == m-1 and j != n-1:
                    dp[j] = grid[i][j] + dp[j+1]
                elif j == n-1 and i != m-1:
                    dp[j] = grid[i][j] + dp[j]
                elif j != n-1 and i != m-1:
                    dp[j] = grid[i][j] + min(dp[j], dp[j+1])
                else:
                    dp[j] = grid[i][j]
        
        return dp[0]
        
    
```