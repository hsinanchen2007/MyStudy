### 解题思路
bfs遍历，每次把每个格点的所有可能性都走一遍，记录cost，并更新最小的cost就行了。

### 代码

```python3
class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        dx = [0, 0, 1, -1]
        dy = [1, -1, 0, 0]

        import queue
        store = queue.Queue()
        dis = [[100000000 for i in range(len(grid[0]))] for j in range(len(grid))]
        store.put([0, 0])
        dis[0][0] = 0
        while not store.empty():
            [x, y] = store.get()
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if nx<0 or nx>=len(grid) or ny<0 or ny>=len(grid[0]):
                    continue
                new_dis = dis[x][y] + 0 if i+1 == grid[x][y] else dis[x][y] + 1
                if new_dis<dis[nx][ny]:
                    dis[nx][ny] = new_dis
                    store.put([nx, ny])
        return dis[len(grid)-1][len(grid[0])-1]

```