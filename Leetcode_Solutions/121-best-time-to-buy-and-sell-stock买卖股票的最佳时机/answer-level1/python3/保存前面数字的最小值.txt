```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_len=0
        if not prices:
            return 0
        min=prices[0]
        for i in prices:
            if i<min:
                min=i
            if i-min>max_len:
                max_len=i-min
        return max_len
```
