先排序，后一次遍历比对。
```
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        h=heights.copy()
        h.sort()
        c=0
        for i,ele in enumerate(h):
            if ele!=heights[i]:
                c+=1
        return c
```
