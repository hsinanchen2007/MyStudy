### 解题思路
直接考虑动态规划的转移方程，dp[i]的最大乘积，可以等于max(dp[i-j]的最大乘积*dp[j]的最大乘积),考虑到2,3,5...这些质数m的最大乘积为m-1, 但是作为dp[i-j]或dp[j]时应看作为m, 所以动态转移方程为：dp[i]=max(dp[i],max(dp[i-j],i-j)*max(dp[j],j))

### 代码

```python
class Solution(object):
    def integerBreak(self, n):
        # dp[i]=max(dp[i],dp[i-j]*dp[j]) for j in range(i)
        dp=[0]+[i for i in range(n)]

        for i in range(2,n+1):
            for j in range(2,i):
                dp[i]=max(dp[i],max(dp[i-j],i-j)*max(dp[j],j))
        return dp[n]

        """
        :type n: int
        :rtype: int
        """
```