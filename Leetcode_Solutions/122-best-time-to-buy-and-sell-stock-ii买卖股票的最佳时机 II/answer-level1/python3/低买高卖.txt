只需要遍历一遍，遍历的过程中，遇到比前一天低就买入，比前一天高就卖出。

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0

        pre_price = prices[0]
        holding = False
        hold_price = 0
        total = 0
        i = 1
        while i < len(prices):
            cur_price = prices[i]
        
            if cur_price > pre_price and not holding: # 价格要走高，立即买入
                hold_price = pre_price
                holding = True
            elif cur_price < pre_price and holding: # 价格要走低，立即卖出
                total += pre_price - hold_price
                holding = False
            
            pre_price = cur_price
            i += 1
        
        # 最后卖出一次
        if holding and cur_price > hold_price:
            total += cur_price - hold_price
        
        return total
```
