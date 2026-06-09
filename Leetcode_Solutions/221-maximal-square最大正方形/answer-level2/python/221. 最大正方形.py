### 解题思路
动态规划，定义dp表示当前位置所能组成的最大正方形的边长
核心状态转义方程式：dp[i + 1][j + 1] = min(dp[i][j], dp[i][j + 1], dp[i + 1][j]) + 1
（与编辑距离的状态转义方程式一样）
为方便计算，减少边界判断，matrix[i][j] 对应 dp[i + 1][j + 1], dp的0行和0列都为0
题目要求返回最大正方形的面积 = 最大边长的平方
### 代码

```python
class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        res = 0
        if matrix:
            m = len(matrix)
            n = len(matrix[0])
    
            dp = [[0 for j in range(n + 1)] for i in range(m + 1)]
    
            for i in range(m):
                for j in range(n):
                    if matrix[i][j] == '1':
                        dp[i + 1][j + 1] = min(dp[i][j], dp[i][j + 1], dp[i + 1][j]) + 1
                        res = max(res, dp[i + 1][j + 1])

        return res * res
```