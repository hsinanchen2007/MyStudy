### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l = len(prices)
        #print("l=",l)
        if l<2: return 0
        res = 0
        dp1 = [0 for i in range(l)]
        #print("dp1=",dp1)
        max_price,min_price = prices[0],prices[0]
        #print("max_price=",max_price)
        #print("min_price=",min_price)
        for i in range(1,l):
            dp1[i] = max(dp1[i-1],prices[i]-min_price)
            #print("dp1[i]=",dp1)
            min_price = min(min_price, prices[i])
            #print("min_price=",min_price)
            max_price = max(max_price, prices[i])
            #print("max_price=",max_price)
        res = dp1[-1]
        dp2 = [0 for i in range(l)]
        max_price = prices[-1]
        for i in range(l-2,-1,-1):
            dp2[i] = max(dp2[i+1], max_price-prices[i])
            #print("dp2[i]=",dp2)
            max_price = max(max_price,prices[i])
            res=max(res,dp1[i-1]+dp2[i]) if i>=1 else max(res,dp2[i])
        return res
```