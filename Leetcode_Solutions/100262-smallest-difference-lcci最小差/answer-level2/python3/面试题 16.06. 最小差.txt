### 解题思路

排序验证

### 代码

```python []
class Solution:
    def smallestDifference(self, a: List[int], b: List[int]) -> int:
        d = {**dict.fromkeys(a, 0), **dict.fromkeys(b, 1)}
        if len(d) < len(a) + len(b):
            return 0
        c = sorted(d)
        return min((abs(c[i] - x) for i, x in enumerate(c[1: ]) if d[c[i]] ^ d[x]))
```