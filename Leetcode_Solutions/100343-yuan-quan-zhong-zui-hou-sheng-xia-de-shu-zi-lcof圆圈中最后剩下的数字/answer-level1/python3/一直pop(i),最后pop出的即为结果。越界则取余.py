### 解题思路
一直pop(i),最后pop出的即为结果。越界则取余

### 代码

```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        s = [i for i in range(n)]
        i = m - 1
        while s:
            if i > len(s) - 1:
                i = i % len(s)
            t = s.pop(i)
            i = i + m - 1
        return t
```