动态规划标准流程：
一、确定问题的状态
二、写出状态转移方程
三、找到边界条件
四、返回
```
class Solution:
    def sumNums(self, n: int) -> int:
        #确定状态
        dp = [0]*(n+1)
        #确定边界条件
        dp[0] = 0
        for i in range(1,n+1):
        #状态转移方程
            dp[i] = dp[i-1]+i
        return dp[n]

```
