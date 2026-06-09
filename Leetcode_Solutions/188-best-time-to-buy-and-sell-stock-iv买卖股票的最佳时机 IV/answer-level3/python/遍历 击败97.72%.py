### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if not prices:
            return 0
        if k >= len(prices) // 2:
            return sum(x - y for x, y in zip(prices[1:], prices[:-1]) if x > y)
        profits = [0] * (len(prices))
        for j in range(k):
            preprofit = 0
            for i in range(1, len(prices)):
                profit = prices[i] - prices[i-1]
                # preprofit代表到当前的这个位置，前一轮的时候在这前面所能取得最大profit的交易，
                # 如果当前进行这笔交易，可以获得的最大profit，和上一轮时在此获得的最大交易进行比较
                # 所以不会出现每次交易都在最大profit的地方
                preprofit = max(preprofit+profit, profits[i])
                # preprofit与在这一步不进行任何交易获得的结果中取大的
                profits[i] = max(preprofit, profits[i-1])
        return profits[-1]
                
```