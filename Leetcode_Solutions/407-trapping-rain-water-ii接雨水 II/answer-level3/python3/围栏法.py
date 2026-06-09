### 解题思路
-   围栏法

首先我们将最外围的一圈看成是围墙，向里面更新围墙的高度

由于雨水会从最低的位置流出，因此我们从围墙最低的位置开始，判断墙内的是能否积水，如果能够积水，表示墙内的节点高度较小，这时候能够累计差值的水，并更新这个点的墙的高度

不断从最低处向内更新墙的高度，直到所有节点都被访问为止




### 代码

```python3
import heapq


class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        if not heightMap:
            return 0
        row, col = len(heightMap), len(heightMap[0])
        ans = 0
        heap = []
        visited = [[0 for _ in range(col)] for _ in range(row)]

        # 上下左右-坐标
        surround = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        # 坐标验证
        def available(m, n):
            return 0 <= m < row and 0 <= n < col

        for i in range(row):
            heap.append([heightMap[i][0], i, 0])
            heap.append([heightMap[i][col - 1], i, col - 1])
            visited[i][0] = 1
            visited[i][col - 1] = 1

        for j in range(1, col - 1):
            heap.append([heightMap[0][j], 0, j])
            heap.append([heightMap[row - 1][j], row - 1, j])
            visited[0][j] = 1
            visited[row - 1][j] = 1

        heapq.heapify(heap)

        while heap:
            height, x, y = heapq.heappop(heap)
            for dx, dy in surround:
                nx, ny = x + dx, y + dy
                if available(nx, ny) and not visited[nx][ny]:
                    cur = [max(height, heightMap[nx][ny]), nx, ny]
                    ans += max(0, cur[0] - heightMap[nx][ny])
                    heapq.heappush(heap, cur)
                    visited[nx][ny] = 1
        return ans

```