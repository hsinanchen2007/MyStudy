```
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        #用每个正方形右下角的数来判断
        #dp中每个位置的数的值代表他的左上部分最大的正方形的长度
        #同时，这个数也是他左上部分一共参与了几个三角形
        m, n = len(matrix), len(matrix[0])
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        
        for i in range(m):
            for j in range(n):
                if matrix[i][j] > 0:
                    dp[i+1][j+1] = min(dp[i][j], dp[i][j+1], dp[i+1][j]) + 1
        return sum([sum(dp[i]) for i in range(1, m+1)])
```

