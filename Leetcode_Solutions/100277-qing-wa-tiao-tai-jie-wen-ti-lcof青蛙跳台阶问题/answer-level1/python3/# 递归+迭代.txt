```python
class Solution:
    def numWays_0(self, n: int) -> int:
        '''递归'''
        if n<2:return 1
        return self.numWays_0(n-1)+self.numWays_0(n-2)

    def numWays_1(self, n: int) -> int:
        '''迭代'''
        if n in [0,1]:return 1
        dp = [0]*(n+1)
        dp[0],dp[1]=1,1
        for i in range(2,n+1):
            dp[i] = (dp[i-1]+dp[i-2])%1000000007
        return dp[-1]

    def numWays_2(self, n: int) -> int:
        '''迭代节省空间'''
        if n in [0,1]:return 1
        dp =[1,1]
        m =0
        for i in range(2,n+1):
            dp[(i+1)%2] = (dp[0]+dp[1])%1000000007
            m = (i+1)%2
        return dp[m]
```
