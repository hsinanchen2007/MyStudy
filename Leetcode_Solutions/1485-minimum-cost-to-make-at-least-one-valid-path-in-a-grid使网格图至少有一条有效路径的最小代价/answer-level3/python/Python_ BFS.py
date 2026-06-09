### 解题思路
题目描述中提到了有效路径不需要是最短路径，但其实我们把换方向的代价理解为距离，那么我们仍然是要寻找‘最短路径’。由此自然想到BFS。那么到底怎么分层呢？

第0层，也就是0代价：从(0,0)开始不需要变换方向就能到达的格子。第1层：所有前一层的格子变换一次方向能到达的格子，以及这些格子不需要变换方向就能到达的格子。以此类推就能找到最后一个格子，保证到达时一定是最小代价。我们用两个list: q, s交替分层。在数据量不大的情况下，我们简单的用Python list模拟queue。需要注意的是维护一个访问过的hash set，防止重复访问和误更新。

### 代码

```python
class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        sign = [(), (0, 1), (0, -1), (1, 0), (-1, 0)]
        q, seen, s = [], set(), []
        i, j = 0, 0
        cost = 0
        while 0 <= i < m and 0 <= j < n and (i, j) not in seen:
            seen.add((i, j))
            q.append((i, j))
            di, dj = sign[grid[i][j]]
            i, j = i + di, j + dj
        while q:
            while q:
                i, j = q.pop(0)
                if (i, j) == (m-1, n-1): return cost
                for (i, j) in [(i+1, j), (i-1, j), (i, j+1), (i, j-1)]:
                    while 0 <= i < m and 0 <= j < n and (i, j) not in seen:
                        seen.add((i, j))
                        s.append((i, j))
                        di, dj = sign[grid[i][j]]
                        i, j = i + di, j + dj
            cost +=1
            q, s = s, q
```