### 解题思路
空间复杂度O(mn)

### 代码

```python
class Solution(object):
    def maximalSquare(self, matrix):
        if not matrix:return 0
        r = len(matrix)
        c = len(matrix[0])
        #dp[i][j]表示该点处能形成的正方形边长大小
        dp = [[0]*c for _ in range(r)]
        max_len = 0 #初始化最大正方形边长
        for i in range(c):
            dp[0][i] = int(matrix[0][i])
            max_len = max(max_len,dp[0][i])
        for i in range(r):
            dp[i][0] = int(matrix[i][0])
            max_len = max(max_len,dp[i][0])
        for i in range(1,r):
            for j in range(1,c):
                if matrix[i][j] == '0':continue
                else:
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j-1],dp[i][j-1]) + 1
                    max_len = max(max_len,dp[i][j])
        return max_len * max_len
```