**---------------------UF----------------------**
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        row=len(grid)
        col=len(grid[0])
        dummy_node=row*col
        parents=[i for i in range(row*col+1)]

        def getIndex(x,y):
            return x*col+y

        def find(p):
            while not p==parents[p]:
                parents[p]=parents[parents[p]]
                p=parents[p]
            return p
        
        def union(p,q):
            nonlocal res
            p_root=find(p)
            q_root=find(q)
            if p_root==q_root:
                return 
            parents[p_root]=q_root
            res-=1

        directions=[(1,0),(0,1)]
        res=row*col+1

        for i in range(row):
            for j in range(col):
                if grid[i][j]=="1":
                    for direction in directions:
                        new_i=i+direction[0]
                        new_j=j+direction[1]
                        if new_i<row and new_j<col and grid[new_i][new_j]=="1":
                            union(getIndex(new_i,new_j),getIndex(i,j))
                else:
                    union(getIndex(i,j),dummy_node)
        return res-1
**------------------------BFS---------------------------**
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        from collections import deque
        if not grid:
            return 0

        m=len(grid)
        n=len(grid[0])

        queue=deque([])
        visited=set()
        directions=[[-1,0],[1,0],[0,1],[0,-1]]
        res=0
        def Is(x,y):
            return x>=0 and x<m and y>=0 and y<n
            
        def bfs(x,y):
            queue.append((x,y))
            while queue:
                x,y=queue.popleft()
                for direction in directions:
                    new_x=x+direction[0]
                    new_y=y+direction[1]
                    if Is(new_x,new_y) and (new_x,new_y) not in visited and grid[new_x][new_y]=="1":
                        visited.add((new_x,new_y))
                        queue.append((new_x,new_y))

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]=="1" and (i,j) not in visited:
                    visited.add((i,j))
                    res+=1
                    bfs(i,j)
        return res


**------------------------DFS---------------------------**
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        from collections import deque
        if not grid:
            return 0

        m=len(grid)
        n=len(grid[0])

        queue=deque([])
        visited=set()
        directions=[[-1,0],[1,0],[0,1],[0,-1]]
        res=0
        def Is(x,y):
            return x>=0 and x<m and y>=0 and y<n
            
        def dfs(x,y):
            for direction in directions:
                new_x=x+direction[0]
                new_y=y+direction[1]
                if Is(new_x,new_y) and (new_x,new_y) not in visited and grid[new_x][new_y]=="1":
                    visited.add((new_x,new_y))
                    dfs(new_x,new_y) 

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]=="1" and (i,j) not in visited:
                    visited.add((i,j))
                    res+=1
                    dfs(i,j)
        return res