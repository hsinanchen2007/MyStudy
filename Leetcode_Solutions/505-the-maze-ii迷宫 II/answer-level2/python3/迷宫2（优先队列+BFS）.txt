> 类似于单源最短路径
```python
import heapq

class Solution(object):
    def shortestDistance(self, maze, start, destination):
        """
        :type maze: List[List[int]]
        :type start: List[int]
        :type destination: List[int]
        :rtype: int
        """
        
        direction = [(0,1),(0,-1),(1,0),(-1,0)]
        m,n = len(maze),len(maze[0])
        start,destination = tuple(start),tuple(destination)
        stack = [(0,start)]
        visited = set()
        
        while stack:
            path,cur = heapq.heappop(stack)
            if cur == destination:
                return path
            visited.add(cur)
            for dx,dy in direction:
                x,y = cur
                length = 0
                while x+dx >= 0 and x+dx < m and y+dy >= 0 and y+dy < n and maze[x+dx][y+dy] == 0:
                    x,y = x+dx,y+dy
                    length += 1
                if (x,y) not in visited:
                    heapq.heappush(stack,(path+length,(x,y)))
        
        return -1
```