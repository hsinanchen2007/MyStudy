### BFS解题思路
使用标准的BFS思路，每次朝八个方向延展。很重要的一点是 要在延展的时候 就把这些被延展的点标为visited，不然会超时的。
#### 代码
```python3
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if not grid or grid[0][0] == 1 or grid[n-1][n-1] == 1:
            return -1
        elif n <= 2:
            return n
        queue = [(0, 0, 1)]
        grid[0][0] = 1
        while queue:
            i, j, step = queue.pop(0)           
            for dx, dy in [(-1,-1), (1,0), (0,1), (-1,0), (0,-1), (1,1), (1,-1), (-1,1)]:
                if i+dx == n-1 and j+dy == n-1:
                    return step + 1
                if 0 <= i+dx < n and 0 <= j+dy < n and grid[i+dx][j+dy] == 0:
                    queue.append((i+dx, j+dy, step+1))
                    grid[i+dx][j+dy] = 1  # mark as visited                   
        return -1
```
### A* Search (启发式搜索)
把普通的queue改为priority queue (heapq) 然后每次优先走离终点近的点。难点是怎么定义这个优先级，这里参考：[https://leetcode-cn.com/problems/shortest-path-in-binary-matrix/solution/qi-fa-shi-sou-suo-xiao-guo-bu-cuo-by-ari-5/]()
```python
def heuristic(x, y):
    return max(abs(n-1 - x), abs(n-1 - y))
```
然后优先级的总分为 `heuristic + step (distance from source)`
#### 代码
```python3
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:       
        n = len(grid)
        if not grid or grid[0][0] == 1 or grid[n-1][n-1] == 1:
            return -1
        elif n <= 2:
            return n

        def heuristic(x, y):
            return max(abs(n-1 - x), abs(n-1 - y))
        
        h = []
        heapq.heappush(h,(0, (0, 0, 1)))
        visited = set()
        while h:
            _, (i, j, step) = heapq.heappop(h)

            if (i, j) in visited:
                continue
            visited.add((i, j))

            for dx, dy in [(-1,-1), (1,0), (0,1), (-1,0), (0,-1), (1,1), (1,-1), (-1,1)]:
                next_i, next_j = i+dx, j+dy

                if next_i == n - 1 and next_j == n - 1:
                    return step + 1

                if 0 <= next_i < n and 0 <= next_j < n and grid[next_i][next_j] == 0:
                    heapq.heappush(h, (step + heuristic(next_i, next_j), (next_i, next_j, step+1)))

        return -1
```
