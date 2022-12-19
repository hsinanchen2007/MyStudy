
```python
class Solution:

    def lastRemaining(self, n: int) -> int:
        def helper(n):
            if n == 1:
                return 1
            return n + 1 - helper(n//2)*2 + (n & 1 == 0)
        return helper(n)
```
通过减法把从右往左的消去对应成从左往右的