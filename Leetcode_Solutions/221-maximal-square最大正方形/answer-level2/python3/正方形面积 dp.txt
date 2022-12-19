### 解题思路
dp[i][j]为以(i,j)为左下角的正方形的最大面积
转移为 dp[i][j]从左/上/左上三个位置取最小+1. (因为左边和上边边长相等), 这样才能保证取到左边最小和上边最小长度的边
因此可以把空间优化到O(1), 即只保存那三个位置的值
### 代码

```python3
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix: return 0
        h, w = len(matrix), len(matrix[0])
        dp = [[0]*(w+1) for _ in range(h+1)] # dp[i][j] (i,j)为右下角的最大边长
        for i in range(1, h+1):
            for j in range(1, w+1):
                if matrix[i-1][j-1]=='1':
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])+1
        return max([max(x) for x in dp])**2
```