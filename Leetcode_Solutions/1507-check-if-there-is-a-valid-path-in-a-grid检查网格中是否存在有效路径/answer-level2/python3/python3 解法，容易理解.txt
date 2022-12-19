   想了半天没想出来，把大神[@sun-man-man](/u/sun-man-man/)的代码看明白之后自己敲了一遍，放出来大家共同学习~~
   每个方格grid[x][y]均有入口和出口，可以根据入口和出口的方向对各个grid[x][y]进行分类，然后对入口前面的方格和出口后面的方格判断其能否形成通路。

```
import collections
class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        q = collections.deque([(0, 0)])
        occupied = {(0, 0)}
        
        while q:
            x, y = q.popleft()
            if x==m-1 and y==n-1:
                return True
            z = grid[x][y]
            
            // (1, 3, 5)的水平入口方向向右，所以grid[x][y-1]的水平出口方向向右，即(1, 4, 6)
            if z in (1, 3, 5) and y>0 and grid[x][y-1] in (1, 4, 6) and (x, y-1) not in occupied:
                q.append((x, y-1))
                occupied.add((x, y-1))

            # (1, 4, 6)的水平出口方向向右，所以grid[x][y+1]的水平入口方向向右，即(1, 3, 5)
            if z in (1, 4, 6) and y<n-1 and grid[x][y+1] in (1, 3, 5) and (x, y+1) not in occupied:
                q.append((x, y+1))
                occupied.add((x, y+1))
            
            # (2, 5, 6)的竖直入口方向向下，所以grid[x-1][y]的竖直出口方向向下，即(2, 3, 4)
            if z in (2, 5, 6) and x>0 and grid[x-1][y] in (2, 3, 4) and (x-1, y) not in occupied:
                q.append((x-1, y))
                occupied.add((x-1, y))

            # (2, 3, 4)的竖直出口方向向下，所以grid[x+1][y]的竖直入口方向向下，即(2, 5, 6)
            if z in (2, 3, 4) and x<m-1 and grid[x+1][y] in (2, 5, 6) and (x+1, y) not in occupied:
                q.append((x+1, y))
                occupied.add((x+1, y))
        return False




```
