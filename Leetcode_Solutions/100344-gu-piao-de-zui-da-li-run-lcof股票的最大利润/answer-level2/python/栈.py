### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:return 0
        stac = [prices[0]]
        ans = 0
        for i in range(1,len(prices)):
            while stac and prices[i]<=stac[-1]:
                stac.pop()
            stac.append(prices[i])
            ans = max(ans,stac[-1]-stac[0])
        return ans
```