### 解题思路
使用bfs来做这道题，创建了一个数组来记录是否遍历过

### 代码

```python3
class Solution:
    def hasPath(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
        n, m = len(maze), len(maze[0])
        d = [[-1 for i in range(m)] for j in range(n)]
        d[start[0]][start[1]] = 0

        queue = [(start[0],start[1])]
        dx = [-1, 0 , 1, 0]    # !!!网格遍历的技巧：左，上，右，下
        dy = [0, 1, 0, -1]

        while queue:
            x,y = queue.pop(0)
            if x == destination[0] and y == destination[1]:
                return True
            for i in range(4):
                a = x
                b = y
                while a+dx[i]>=0 and a+dx[i]<n and b+dy[i]>=0 and b+dy[i]<m and maze[a+dx[i]][b+dy[i]]==0:
                    a += dx[i]
                    b += dy[i]
                if d[a][b] == -1:
                    d[a][b] = d[x][y] + 1
                    queue.append((a, b))
        return False
```