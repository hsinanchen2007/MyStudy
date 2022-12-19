
```
class Solution:
    def __init__(self):
        self.directions = [(-1,0),(0,1),(1,0),(0,-1)]
        
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        h = len(grid)
        w = len(grid[0])
        area = 0
        flag = [[0 for _ in range(w)] for __ in range(h)]
        for i in range(h):
            for j in range(w):
                if grid[i][j] == 0 or flag[i][j] == 1:
                    continue
                stack = [(i,j)]
                flag[i][j] = 1
                area_temp = 0
                while stack:
                    d = stack.pop()
                    area_temp += 1
                    for direct in self.directions:
                        i_,j_ = d[0]+direct[0],d[1]+direct[1]
                        if 0<=i_<h and 0<=j_<w and grid[i_][j_] == 1 and flag[i_][j_] == 0:
                            stack.append((i_,j_))
                            flag[i_][j_] = 1
                area = max(area,area_temp)
                print(area)
        return area
```
