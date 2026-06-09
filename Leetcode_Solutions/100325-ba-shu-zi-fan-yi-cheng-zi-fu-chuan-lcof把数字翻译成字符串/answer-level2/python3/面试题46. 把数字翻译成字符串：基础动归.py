
```python []
class Solution:
    def translateNum(self, num: int) -> int:
        s = str(num)
        d = [1] + [0] * len(s)
        for i in range(1, len(s) + 1):
            d[i] = d[i - 1] + ('10' <= s[i - 2: i] < '26' and d[i - 2])
        return d[-1]
```