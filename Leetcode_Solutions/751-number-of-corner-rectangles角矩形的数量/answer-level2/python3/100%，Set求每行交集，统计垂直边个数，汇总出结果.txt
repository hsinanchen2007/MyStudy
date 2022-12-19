执行用时 :
760 ms, 在所有 python3 提交中击败了100.00%的用户
内存消耗 :
14.7 MB, 在所有 python3 提交中击败了100.00%的用户

```
class Solution:
    def countCornerRectangles(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        m=len(grid)
        n=len(grid[0])
        points=[]
        for i in range(m):
            line=set([])
            for j in range(n):
                if grid[i][j]==1:
                    line.add(j)
            points.append(line)
        
        res=0
        pl=len(points)
        for i in range(pl):
            for j in range(i+1,pl):
                count=len(points[i].intersection(points[j]))
                res+=(count*(count-1)//2)
        return res
```
