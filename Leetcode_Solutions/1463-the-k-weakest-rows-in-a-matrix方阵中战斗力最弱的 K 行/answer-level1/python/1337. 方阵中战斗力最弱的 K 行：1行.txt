![image.png](https://pic.leetcode-cn.com/a4568e2370e35ced8174efc3b4a10554ef2b558aa0ac183f067fb23567338c3d-image.png)

```python []
class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        return [i for _, i in sorted((m.count(1), i) for i, m in enumerate(mat))][: k]
```