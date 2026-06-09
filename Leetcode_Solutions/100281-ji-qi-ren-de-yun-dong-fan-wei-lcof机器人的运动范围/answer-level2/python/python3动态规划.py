`dp[i][j]`表示坐标`[i,j]`能否抵达
易得出`dp[i][j]=dp[i][j]&(dp[i-1][j]|dp[i][j-1])`
```python
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        dp=[[1]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if sum(map(int,str(i)+str(j)))>k:
                    dp[i][j]=0
        for i in range(1,m):
            dp[i][0]&=dp[i-1][0]
        for j in range(1,n):
            dp[0][j]&=dp[0][j-1]
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j]&=dp[i-1][j]|dp[i][j-1]
        return sum(map(sum,dp))
```