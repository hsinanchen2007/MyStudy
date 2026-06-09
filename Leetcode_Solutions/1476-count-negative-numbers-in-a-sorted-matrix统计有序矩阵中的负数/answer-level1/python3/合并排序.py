```
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        if not grid:return 0
        mid_list = []
        for i in grid:
            mid_list.extend(i)
        mid_list = sorted(mid_list)
        res = 0
        for i in mid_list:
            if i < 0:res += 1
            else:break
        return res
```
