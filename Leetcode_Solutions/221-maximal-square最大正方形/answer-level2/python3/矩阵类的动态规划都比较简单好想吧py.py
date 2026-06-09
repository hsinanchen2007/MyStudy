```
矩阵类的动态规划都很简单，因为dp本来就是一个矩阵，具体看注解
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        # dp思想
        # case 
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return 0
        m = len(matrix)
        n = len(matrix[0])
        max_len = 0
        dp = [[0] * n for i in range(m)]
        # 状态定义成 “当前点为正方形的右下方的顶点时，正方形的最大面积”
        for i in range(m):
            for j in range(n):
                # ...注意应该是于 '1' 进行判断
                if matrix[i][j] == "1":
                    # 注意到base case,当matrix[i][j] == 1直接赋1
                    if i == 0 or j == 0:
                        dp[i][j] = 1
                    else:
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1],dp[i-1][j-1]) + 1
                    max_len = max(dp[i][j], max_len)
        return max_len * max_len
```
