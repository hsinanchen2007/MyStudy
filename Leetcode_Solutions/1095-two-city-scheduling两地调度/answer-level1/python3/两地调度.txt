借鉴评论中的思路（2N人去A城，再选取N人去B城）。
时间98，空间100。

```
class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        delt = []
        i = 0
        r = 0
        n = len(costs)
        while (i < n):
            delt.append(costs[i][1]-costs[i][0])
            r += costs[i][0]
            i += 1
        delt.sort()
        return r + sum( delt[0:n//2] )
```
