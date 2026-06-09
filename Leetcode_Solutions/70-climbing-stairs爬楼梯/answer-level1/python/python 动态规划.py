搞清楚动态方程其他OK，dp[i]=dp[i-1]+dp[i-2]
class Solution(object):
    def climbStairs(self, n):
        if n==2:
            return 2
        if n==1:
            return 1
        dp=[[] for i in range(n)]
        dp[0]=1
        dp[1]=2
        for i in range(n-2):
            dp[i+2]=dp[i+1]+dp[i]
        return dp[n-1]