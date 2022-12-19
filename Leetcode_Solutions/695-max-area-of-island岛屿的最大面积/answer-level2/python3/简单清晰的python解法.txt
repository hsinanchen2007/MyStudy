```
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        h = len(grid)
        w = len(grid[0])
        
        if h<1 or w<1:
            return 0
        
        # 存储节点是否被访问
        access = [[0 for i in range(w)] for j in range(h)]
        area = 0
        
        def recur(i,j,h,w):
            # 访问的索引不能超过岛屿范围
            if i >= h or j >= w or i<0 or j<0:
                return 0
            
            # 访问节点为 "水"
            if grid[i][j] == 0:
                access[i][j] = 1
                return 0
            
            # 该结点已被访问过
            if access[i][j] == 1:
                return 0
            
            access[i][j] = 1
            return recur(i+1,j,h,w) + recur(i,j+1,h,w) + recur(i-1,j,h,w) + recur(i,j-1,h,w) + 1
            
        
        for i in range(h):
            for j in range(w):
                if access[i][j] == 0:
                    if grid[i][j] == 0:
                        access[i][j] = 1
                        continue
                    else:
                        area = max(recur(i,j,h,w),area)
        return area

```

时间复杂度：O(h*w)
空间复杂度：O(h*w)