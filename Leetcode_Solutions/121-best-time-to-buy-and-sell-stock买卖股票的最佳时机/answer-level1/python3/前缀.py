### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxn = 0;lnn = len(prices)
        if lnn==0:return 0
        d = [0]*(lnn+5);d[0] = prices[0]
        for i in range(1,lnn):
            if prices[i]<d[i-1]:d[i] = prices[i]
            else:d[i] = d[i-1]
            maxn = max(maxn,prices[i]-d[i])
        return maxn
```