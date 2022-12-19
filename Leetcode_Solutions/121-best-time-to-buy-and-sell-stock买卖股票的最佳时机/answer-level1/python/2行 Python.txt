```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        from functools import reduce
        return reduce(lambda r, p: (max(r[0], p-r[1]), min(r[1], p)), prices, (0, float('inf')))[0]
```
- r = (结果，之前遍历过的所有元素中的最小值)


```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        r, m = 0, float('inf')
        for p in prices:
            r, m = max(r, p - m), min(m, p)
        return r
```

