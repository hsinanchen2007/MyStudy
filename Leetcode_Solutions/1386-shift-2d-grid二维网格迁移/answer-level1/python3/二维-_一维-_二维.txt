看了评论区带佬思路又写了一遍，二维展开一维然后再组成二维。刚学py感觉写的有点麻烦，求指点
```
from functools import reduce
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        n, m = len(grid), len(grid[0])
        nlist = reduce(operator.add, grid)
        nlen = len(nlist)
        k = k % nlen
        nlist = nlist[-k:] + nlist[0:nlen-k]

        ans = []
        for i in range(n):
            ans.append([])
            for j in range(m):
                ans[i].append(nlist[i*m+j])
        return ans
```
