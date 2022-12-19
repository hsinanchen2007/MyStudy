```
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # 实际中m=n
        n = len(triangle)
        m = len(triangle[n-1])

        dp = [0]*m
        dp[0] = triangle[0][0]
        for i in range(1,n):
            for j in range(i,-1,-1):
                if j==0:
                    dp[j]=dp[j]+triangle[i][j]
                elif j==i:
                    dp[j]=dp[j-1]+triangle[i][j]
                else:
                    dp[j]=min(dp[j],dp[j-1]) + triangle[i][j]

        return min(dp)
```

