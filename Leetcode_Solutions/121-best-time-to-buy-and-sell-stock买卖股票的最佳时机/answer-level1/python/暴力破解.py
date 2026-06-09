### 解题思路
暴力破解

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        while prices[-1:] == [0]:
            prices.pop()
        i = j = mm = 0
        n = len(prices)
        while i < n:
            j = i 
            while j < n:
                if prices[j] == 0:
                    j += 1
                    continue
                t = prices[j]-prices[i]
                if t > mm:
                    mm = t
                j += 1
            i += 1
        return mm

```