### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        i = 0
        j = 1
        r = 0
        while(j < len(prices)):
            if prices[i] < prices[j]:
                r = r + prices[j] - prices[i]
            i = i + 1
            j = j + 1
        return r
```