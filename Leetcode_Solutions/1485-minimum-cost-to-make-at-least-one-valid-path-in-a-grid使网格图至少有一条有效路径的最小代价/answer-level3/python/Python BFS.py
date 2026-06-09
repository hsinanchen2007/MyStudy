### 大家好，我的博客是: http://erik-chen.github.io/，欢迎交流！
### 解题思路
1. 因为需要计算改变数，因此想到BFS
2. queue储存所有当前这步可以search到的地方
3. visited储存所有历史上search过的地方
4. new_queue储存当前的基础上，改变一个箭头，可以search到的地方
5. 用new_queue代替queue，同时用count记数，进行BFS
6. 当search到右下角，返回count

### 代码

```python3
class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        count = 0
        queue = [(0, 0)]
        visited = {(0, 0)}
        while True:
            for i, j in queue:
                if grid[i][j] == 1:
                    if j+1 < n and (i,j+1) not in visited:
                        queue.append((i,j+1))
                        visited.add((i,j+1))
                elif grid[i][j] == 2:
                    if j-1 >=0 and (i,j-1) not in visited:
                        queue.append((i,j-1))
                        visited.add((i,j-1))
                elif grid[i][j] == 3:
                    if i+1 < m and (i+1,j) not in visited:
                        queue.append((i+1,j))
                        visited.add((i+1,j))
                else:
                    if i-1 >=0 and (i-1,j) not in visited:
                        queue.append((i-1,j))
                        visited.add((i-1,j))
            if (m-1, n-1) in visited:
                return count
            count += 1
            new_queue = []
            for i,j in queue:
                for p, q in zip((i-1,i+1,i,i),(j,j,j-1,j+1)):
                    if (p, q) not in visited and 0<=p<m and 0<=q<n:
                        new_queue.append((p,q))
                        visited.add((p,q))
            queue = new_queue
```