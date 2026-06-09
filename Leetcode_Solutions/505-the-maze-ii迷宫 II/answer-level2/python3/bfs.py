```
class Solution:
    def shortestDistance(self, maze: List[List[int]], start: List[int], destination: List[int]) -> int:
        from collections import deque
        row = len(maze)
        col = len(maze[0])
        visited = [[0]*col for i in range(row)]
        stack = deque()
        stack.appendleft((start[0],start[1]))
       
        
        while stack:
            i,j = stack.pop()
            for x, y in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
                
                tmp_i = i
                tmp_j = j
                while 0 <= tmp_i + x < row and 0 <= tmp_j + y < col and maze[tmp_i + x][tmp_j + y] == 0: 
                    tmp_i += x
                    tmp_j += y
                
                if tmp_i == i and tmp_j == j:
                    continue
                if tmp_i!=i:
                    t = abs(tmp_i-i)
                else:
                    t = abs(tmp_j-j)
                steps = t + visited[i][j]
                if (not visited[tmp_i][tmp_j]) or (steps < visited[tmp_i][tmp_j]):
                    stack.appendleft((tmp_i,tmp_j))
                    visited[tmp_i][tmp_j] = steps
                    
        return visited[destination[0]][destination[1]] if visited[destination[0]][destination[1]] else -1
```
