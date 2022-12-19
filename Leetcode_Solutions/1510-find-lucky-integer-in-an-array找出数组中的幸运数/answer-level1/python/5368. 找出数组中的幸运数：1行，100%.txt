![image.png](https://pic.leetcode-cn.com/94a10280efeb5708fb65f3455d4e25d3103578ac61f6d55eafbce06ee6d97f1b-image.png)

```python []
class Solution:
    def findLucky(self, arr: List[int]) -> int:
        return max(filter(lambda x: x[0] == x[1], collections.Counter(arr).items()), default=(-1, ))[0]
```