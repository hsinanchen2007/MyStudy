![image.png](https://pic.leetcode-cn.com/7a30dc141b9443166b1c515300f27d17448062ee5dfaad94a00a1801b8120a07-image.png)

```python []
class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        d = collections.Counter(i for i, j in zip(s1, s2) if i != j)
        if (d['x'] + d['y']) & 1 or len(s1) != len(s2):
            return -1
        return sum(divmod(d['x'], 2) + divmod(d['y'], 2))
```
