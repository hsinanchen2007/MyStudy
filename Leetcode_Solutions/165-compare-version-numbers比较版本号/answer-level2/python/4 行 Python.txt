```python
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1, v2 = ([*map(int, v.split('.'))] for v in (version1, version2))
        d = len(v2) - len(v1)
        v1, v2 = v1 + [0] * d, v2 + [0] * -d
        return (v1 > v2) - (v1 < v2)
```
- 利用 python 序列比较的性质