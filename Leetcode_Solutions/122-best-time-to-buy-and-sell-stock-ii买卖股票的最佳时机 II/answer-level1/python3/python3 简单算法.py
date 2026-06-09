### 解题思路
这题目的关键思路就是把用当天的股票价格减去昨天的股票价格，只要有利润就卖出，没有就等下一天就好了。比较需要注意的是right，如果在某一天把股票出售，就马上要买入，这保持利润最大化。
left储存利润总数
right存储股票前一天的价格
prices[i]是股票当天的价格
### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if (len(prices)<1): return '0'
        left = 0
        right=prices[0]
        for i in range(1,len(prices)):
            if(prices[i]-right>0):
                left+=prices[i]-right
                right=prices[i]
            elif(prices[i]-right<0):
                right=prices[i]

        return left
```