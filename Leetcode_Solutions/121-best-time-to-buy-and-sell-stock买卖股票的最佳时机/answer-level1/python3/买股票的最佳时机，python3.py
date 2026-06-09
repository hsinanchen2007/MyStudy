### 解题思路
一次遍历，用当前值减去前面的最小值，如果比res大，则对res重新赋值

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1:
            return 0
        small, res = prices[0], 0
        for i in range(1, len(prices)):
            if prices[i] < small:
                small = prices[i]
                continue
            else:
                res = max(res, prices[i]-small)
        return res

        
```