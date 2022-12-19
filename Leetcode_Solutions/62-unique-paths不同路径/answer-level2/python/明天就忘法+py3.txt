### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp=[[0]*n for _ in range(m)]
        for i in range(n):
            dp[0][i]=1
        for j in range(m):
            dp[j][0]=1
        for i in range(1,m):
            for j in range(1,n):
                # 上左的路径相加
                dp[i][j]=dp[i][j-1]+dp[i-1][j]
        return dp[-1][-1]

```