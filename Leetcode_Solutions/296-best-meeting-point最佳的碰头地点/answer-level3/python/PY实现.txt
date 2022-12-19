```
class Solution:
    def minTotalDistance(self, grid: List[List[int]]) -> int:
        R,C,r,c=len(grid),len(grid[0]),[],[]
        for i in range(R):
            for j in range(C):
                if grid[i][j]==1:
                    r.append(i)
                    c.append(j)
        c.sort()
        def d(l):
            mid=l[len(l)//2]
            return sum(abs(l[i]-mid) for i in range(len(l)))
        
        return d(r)+d(c)
```
