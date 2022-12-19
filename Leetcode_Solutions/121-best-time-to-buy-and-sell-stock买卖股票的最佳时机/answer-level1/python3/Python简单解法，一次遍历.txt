### 解题思路
1、if prices[i+1]<prices[i]，此时就应该在prices[i+1]处买入
2、卖出的话，就取差值，同时不断取最大的差值，就是利润
3、代码容易看懂

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        if len(prices)==0:
            return max_profit

        buy_price = prices[0]  ##初始化买入的价格
        for i in range(len(prices)):
            if prices[i]>buy_price: ##此时存在利润
                money  = prices[i]-buy_price
                if max_profit<money:
                    max_profit = money
            else:
                buy_price = prices[i]
        return max_profit


        
```