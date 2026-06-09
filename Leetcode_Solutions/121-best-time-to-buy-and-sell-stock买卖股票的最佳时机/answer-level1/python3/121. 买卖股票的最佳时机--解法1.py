### 解题思路
遍历所有数，取到当前数之前的数里面的较小值，并计算到当前数的利润，取其中的最小值。

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        minc = float('inf')
        for i in prices:
            if i < minc:
                minc = i
            if i-minc >= res:
                res = i-minc
        return res
            
```