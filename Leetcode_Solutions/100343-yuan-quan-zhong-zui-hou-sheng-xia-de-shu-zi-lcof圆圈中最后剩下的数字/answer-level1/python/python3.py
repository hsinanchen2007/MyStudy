### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        l = [i for i in range(n)]
        i = 0
        while len(l) > 1:
            i += m-1
            if i >= len(l): i %= len(l)
            del l[i]
        return l[0]
```