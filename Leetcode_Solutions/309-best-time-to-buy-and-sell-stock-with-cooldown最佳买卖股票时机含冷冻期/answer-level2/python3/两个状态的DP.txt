### 解题思路

- DP
- 设置两个状态，hold[i]和unhold[i]，分别表示第i天时持有及未持有股票的最大利润
- 计算base state，分别写出i=0和i=1的结果
- 写出递推公式，因为有冷冻期，所以前推用到i-2和i-1的值

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # - sanity check
        if (not prices) or (len(prices)==1):
            return 0

        n = len(prices)

        # - dp state
        # - hold[i] means max profit if hold stock at day i
        # - unhold[i] means max profit if not hold stock at day i
        hold = [0] * n
        unhold = [0] * n

        # - base state

        # - hold at day 0 means buy at day 0
        hold[0] = -prices[0]

        # - hold at day 1 means:
        # -   buy at day 0, do nothing at day 1
        # -   or do nothing at day 0, and buy at day 1
        hold[1] = max(-prices[0], -prices[1])

        # - unhold at day 0
        unhold[0] = 0

        # - unhold at day 1 means:
        # -     do nothing at day 0 and day 1
        # -     buy at day 0 and sell at day 1
        unhold[1] = max(0, hold[0]+prices[1])

        # - dp formula

        # - hold[i] = max of
        # -     hold at day i-1, do nothing at day i
        # -     unhold at day i-2, do nothing at day i-1, buy at day i
        # - hold[i] = max(hold[i-1], (unhold[i-2] - prices[i]))

        # - unhold[i] = max of
        # -     unhold at day i-1, do nothing at day i
        # -     hold at day i-1, sell at day i
        # - unhold[i] = max(unhold[i-1], (hold[i-1] + prices[i]))

        for i in range(2, n):
            hold[i] = max(hold[i-1], (unhold[i-2] - prices[i]))
            unhold[i] = max(unhold[i-1], (hold[i-1] + prices[i]))

        return max(hold[n-1], unhold[n-1])
```