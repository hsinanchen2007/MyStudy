```python
    def balancedStringSplit(self, s: str) -> int:
        l_minus_r = res = 0
        for i in s:
            if i == 'L':
                l_minus_r += 1
            else:
                l_minus_r -= 1
            if not l_minus_r:
                res += 1
                l_minus_r = 0
        return res
```
