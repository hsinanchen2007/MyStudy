
```
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:    # 多源BFS搜索
        # 注意一： 这道题最好用BFS，因为BFS的深度刚好代表了距离
        # 注意二： 多源BFS和单源BFS的的本质是一模一样的
        from collections import deque
        queue = deque()
        seen = set()
        for i in range(len(grid)):  # 将多源加入到 queue 中
            for j in range(len(grid)):
                if grid[i][j] == 1:
                    queue.append((i,j))
                    seen.add((i,j))
        
        distance = -1

        while queue:    # 开始进行多源BFS
            distance += 1
            for _ in range(len(queue)):     # 通过len(queue) 来控制 bfs搜索的 深度
                cur_i,cur_j = queue.popleft()
                neighbors = [(cur_i+1,cur_j),(cur_i-1,cur_j),(cur_i,cur_j+1),(cur_i,cur_j-1)]
                for neigh in neighbors:
                    if neigh not in seen:   
                        if neigh[0] >= 0 and neigh[0] <= len(grid)-1 and neigh[1] >=0 and neigh[1] < len(grid):         # 除了不能在seen中，还不能超出范围
                            seen.add(neigh)
                            queue.append(neigh)
 
        return distance if distance > 0 else -1

```
