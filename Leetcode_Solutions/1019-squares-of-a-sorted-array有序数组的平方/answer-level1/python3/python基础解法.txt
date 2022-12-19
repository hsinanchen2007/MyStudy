解题思路：1. 先排序，后平方 2. 先平方后排序。
代码
```
class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        # return [i**2 for i in sorted([abs(i) for i in A])]
        return sorted([i**2 for i in A])

```
