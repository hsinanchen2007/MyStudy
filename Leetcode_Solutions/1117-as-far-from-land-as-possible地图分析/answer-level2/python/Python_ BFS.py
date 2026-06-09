### 解题思路
此题的核心思想是找到每块水面离陆地的最小距离（并且用二维数组记录下来），然后返回其中离陆地最远的那块水面（狗头）。既然是要先求最近距离，那么自然想到BFS。

首先BFS起点为陆地，陆地离陆地的最近距离为0。接下来第一层是离陆地距离为1的水面，访问过的水面用一个set记录，防止重复访问节省时间，同时也防止误更新，因为一个水面和陆地的距离可能有好几个方向，我们只要记录最小的那个。BFS每一层的距离都在上一层及基础上加一。遍历每一块水面后，我们可以得到距离陆地最远的那块水面。

代码里面使用Python 的 list来实现queue的功能，对于小量的数据是可以的，如果数据很大的话，最好还是用queue来实现。

### 代码

```python
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n = len(grid)
        q = [(i, j) for i in range(n) for j in range(n) if grid[i][j] == 1]
        if not q or len(q) == n*n: return -1
        s, seen = [], set(q)
        dp = [[0 for _ in range(n)] for _ in range(n)]
        while q:
            while q:
                i, j = q.pop(0)
                for x, y in [(i+1, j), (i-1, j), (i, j+1), (i, j-1)]:
                    if 0 <= x < n and 0 <= y < n and (x, y) not in seen:
                        seen.add((x, y))
                        s.append((x, y))
                        dp[x][y] = dp[i][j] + 1
            q, s = s, q
        return max(dp[i][j] for i in range(n) for j in range(n))
    
```