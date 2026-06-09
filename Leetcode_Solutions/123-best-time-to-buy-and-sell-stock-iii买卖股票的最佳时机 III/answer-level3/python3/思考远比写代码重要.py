### 解题思路
写好状态转移方程，搞清初始条件，然后结果就出来了。

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        # 使用(i,k,s)三元组来表示当前状态
        # i表示当前交易位置
        # k第几次交易,k从0开始，如果k=-1是不可能存在
        # s表示是否持股
        if n == 0:
            return 0
        dp = {}
        for i in range(n): 
            if i-1 == -1:
                dp[(-1,0,0)] = dp[(-1,1,0)] = 0
                dp[(-1,0,1)] = dp[(-1,1,1)] = -float('inf')
            for k in (0,1):
                # 遍历k的取值
                if k-1 == -1:
                    dp[(i-1,k-1,0)] = 0
                # sell
                dp[(i,k,0)] = max(dp[(i-1,k,0)], dp[(i-1,k,1)]+prices[i])
                # buy
                dp[(i,k,1)] = max(dp[(i-1,k-1,0)]-prices[i], dp[(i-1,k,1)])
        return dp[(n-1,1,0)]
```