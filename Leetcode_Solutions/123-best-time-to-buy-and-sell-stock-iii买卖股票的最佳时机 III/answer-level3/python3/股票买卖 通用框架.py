### 解题思路
这道题借鉴了精选题解: 团灭6道股票

这里对i和k都加入了等于0的状态
而且k的遍历要是从大到小的, k代表剩余交易次数, 完整的买和卖算一次, 因此只在买的时候k-1

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0
        l = len(prices)
        dp = [[[0, 0], [0, 0], [0, 0]] for _ in range(l+1)]
        for k in range(3): dp[0][k][1]=float('-inf')
        for i in range(l+1): dp[i][0][1]=float('-inf')
        for i in range(1, l+1):
            for k in range(2, 0, -1):
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+prices[i-1]) # sell
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0]-prices[i-1]) #buy
        return dp[-1][2][0] # 不是返回dp[-1][0][0]!!! 意思是返回最后一天有两次交易次数且手里没股票的最大利润
```