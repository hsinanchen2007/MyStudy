### 解题思路
转移方程为dp[n]=dp[n-1]*(k-1)+dp[n-2]*(k-1)
即当前颜色不等于前一个颜色，或者当前涂色等于前一个颜色
如果当前颜色不等于前一个颜色，前面有k个颜色可以取，所以当前只有k-1个颜色可以涂即dp[i]=dp[i-1]*(k-1)
如果当前颜色和前面的颜色一致，那么它们必须区别于前前个栅栏颜色，即dp[i]=dp[i-2]*(k-1)

### 代码

```python3
class Solution:
    def numWays(self, n: int, k: int) -> int:
      
        dp=[0]*max(n+1,3)
        dp[1]=k
        dp[2]=k*k
        for i in range(3,n+1):
            dp[i] = dp[i-1]*(k-1)+ dp[i-2]*(k-1)
        return dp[n]







        


       
       
```