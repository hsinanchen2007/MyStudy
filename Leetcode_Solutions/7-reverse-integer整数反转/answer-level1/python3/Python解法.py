### 解题思路
Python 解法，欢迎讨论

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        rs, y = 0, abs(x)
        while y != 0:
            rs = rs * 10 + y % 10
            y //= 10
        rs = 0 if (rs>2**31-1 or rs<-2**31) else rs if x > 0 else -rs
        return rs