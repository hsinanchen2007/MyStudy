![122.jpg](https://pic.leetcode-cn.com/13508e49075d1ec237f517f9a1fadc687694f6ea16c09953a0f1b697bfd80cc9-122.jpg)

方法A：
```class Solution:
    def maxProfit(self, p: List[int]) -> int:
        a=b=f=0
        for i in range(len(p)-1):
            if f:
                if p[i]>=p[i+1]:
                    f=False
                    b+=p[i]-a
            elif p[i]<p[i+1]:
                f=True
                a=p[i]
                    
        if f:
            return b+p[-1]-a
        else:
            return b
```
思路：如果持有股票并且明天价格小于等于今天的价格，就卖掉。如果不持有并且明天价格大于今天价格，就买入。

方法B：
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        s=0
        for i in range(len(prices)-1):
            if prices[i]<prices[i+1]:
                s+=prices[i+1]-prices[i]
        return s
```
思路：如果我们持有股票，那么明天上涨我们肯定赚钱。如果没有持有股票，今天买入明天一样赚钱。所以只要上涨我们就赚钱。