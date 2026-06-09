### 解题思路
时间复杂度：O（n）
空间复杂度：O（n）

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        价格降低不买入，价格升高不卖出；升高前买入，降低前卖出
        """
        if not prices:
            return 0
        if len(prices) == 1:
            return 0
        benefit = 0
        own_price = None
        for ind, e in enumerate(prices):
            if own_price is None and ind < len(prices) - 1:
                if e < prices[ind+1]:
                    own_price = e
                    continue
            if own_price is not None and 0 < ind < len(prices) - 1:
                if prices[ind-1] < e < prices[ind+1]:
                    continue
                elif prices[ind-1] <= e > prices[ind+1]:
                    benefit += e - own_price
                    own_price = None
                elif prices[ind-1] > e < prices[ind+1]:
                    own_price = prices[ind]
                elif prices[ind-1] > e > prices[ind+1]:
                    continue
            if 0 < ind == len(prices) - 1:
                if own_price is not None:
                    benefit += e - own_price
        return benefit


```