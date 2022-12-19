### 解题思路
多源广度遍历，每一层其实就是距离+1

### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        if not grid:
            return 
        H = len(grid)
        W = len(grid[0])
        que = []
        flag = False
        for i in range(H):
            for j in range(W):
                if grid[i][j] == 1:
                    que.append((i,j,0))
                if grid[i][j] ==0:
                    flag = True
         
        if not flag:
            return -1
        res_dist = -1
        while que:
            i,j,dist = que.pop(0)
            if i+1 < H:
                if grid[i+1][j] == 0:
                    que.append((i+1, j,dist+1))
                    grid[i+1][j] =2
            if j+1 < W:                                 
                if grid[i][j+1] == 0:
                    que.append((i, j+1,dist+1))
                    grid[i][j+1] =2
            if i > 0:                         
                if grid[i-1][j] == 0:
                    que.append((i-1, j,dist+1))
                    grid[i-1][j] =2
            if j > 0:              
                if grid[i][j-1] == 0:
                    que.append((i, j-1, dist+1))
                    grid[i][j-1] =2
            if res_dist < dist:
                res_dist = dist

        return res_dist                                 
                
```