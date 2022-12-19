26进制转十进制

```python
class Solution:
    def titleToNumber(self, s: str) -> int:
        res = 0
        bit = 1
        for a in s[::-1]:
            res += (ord(a) - 64) * bit
            bit *= 26
        return res
```

或者一行代码

```python
import functools
class Solution:
    def titleToNumber(self, s: str) -> int:
        return functools.reduce(lambda x, y: x * 26 + y, [ord(a) - 64 for a in s ])
```


再或者

```python
class Solution:
    def titleToNumber(self, s: str) -> int:
        return sum( (ord(a) - 64) * (26 ** i)  for i, a in enumerate(s[::-1]))
```

