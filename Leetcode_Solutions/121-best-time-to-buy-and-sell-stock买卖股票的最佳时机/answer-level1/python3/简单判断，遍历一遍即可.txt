### 解题思路
只需要遍历prices一遍
判断
- 如果当天的价格低于最低价格：
更新最低价格，并**把最高价格更新为当前价格**（这一步很关键，可以保证卖出在买入之后！因为一旦最低价格更新后，之前曾经出现过的高价已经没有意义）
- 如果当天的价格高于最高价格：
更新最高价格，并计算受益（如果比记录的当前最大收益高，则更新）
### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if prices==[]:return 0
        minprice,maxprice,profit=prices[0],prices[0],0
        for p in prices:
            if p<minprice:
                minprice=p
                maxprice=minprice
            if p>maxprice:
                maxprice=p
                profit=max(profit,maxprice-minprice)
        return profit

```