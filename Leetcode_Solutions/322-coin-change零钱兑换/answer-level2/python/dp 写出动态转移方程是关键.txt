1.写出动态转移方程
dp(i)=min(dp(i-c))+1是关键


### 代码
```python3
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
          
        dp=[float('inf')]*(amount+1)
        dp[0]=0
        for i in range(amount+1):
            for j in coins:
                if i>=j:
                    dp[i]=min(dp[i],dp[i-j]+1)
        if dp[-1]>amount:return -1
        else: return dp[-1]
        


```