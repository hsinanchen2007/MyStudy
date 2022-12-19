### 解题思路
如果股票价格大于买入价，比较当前最大利润与历史最大利润，如果超过则刷新历史最大利润
如果股票价格跌破买入价，则将买入价格重置为当前价格，并重新计算最大利润
取所有最大利润的最大值，则为题解。

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)==0 or not prices:
            return 0
        start_price=prices[0]
        earnlist=[0]
        for i in prices:
            if i>start_price and i-start_price>earnlist[-1]:
                earnlist[-1]=i-start_price
            elif i<start_price:
                start_price=i
                earnlist.append(0)
        return max(earnlist)

```