python3 一行解法，大家不要学

```python3 []
class Solution:
    def trap(self, height: List[int]) -> int:
        return sum(map(min, accumulate(height, max), list(accumulate(height[::-1], max))[::-1])) - sum(height)
```
