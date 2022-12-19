### 解题思路
关键点在于从陆地同时泛起涟漪，这一点可以用queue来实现。一轮queue的清空意味着一层外扩进行完成，在处理queue里的网格式添加的新的网格即为下一层的涟漪。用queue加上for loop可以精准的区别开里一层涟漪和外一层涟漪。假如一个坐标会被多个陆地泛起的涟漪触及到，则最先触碰的为该坐标的值。这里的dist为记录距离的二维数组，陆地都为0，并且添加到queue里作为涟漪发起者，其余坐标设置为-1.

### 代码

```python
class Solution(object):
    def maxDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        dist =[ [-1]*n for i in range(0,n)]
        Q = []
        cnt = 0

        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    dist[i][j] = 0
                    Q.insert(0,(i,j))
                    cnt += 1
        while Q != []:
            upperbound = len(Q)
            for counter in range(0,upperbound):
                (x,y) = Q.pop()
                if (x+1) < n and dist[x+1][y] == -1:
                    dist[x+1][y] = dist[x][y]+1
                    Q.insert(0, (x+1,y) )
                if (x-1) >= 0 and dist[x-1][y] == -1 :
                    dist[x-1][y] = dist[x][y]+1
                    Q.insert(0, (x-1,y) )
                if (y+1) < n and dist[x][y+1] == -1 :
                    dist[x][y+1] = dist[x][y]+1
                    Q.insert(0, (x,y+1) )
                if (y-1) >= 0 and dist[x][y-1] == -1 :
                    dist[x][y-1] = dist[x][y]+1
                    Q.insert(0, (x,y-1) )
        ans = -1
        for i in range(n):
            for j in range(n):
                if dist[i][j] > ans:
                    ans = dist[i][j]
        if ans <= 0:
            return -1
        else:
            return ans        
```