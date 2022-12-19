### 解题思路
最难居然是要先走到附近，然后再Dijkstra。面对这种发散的走法，从0点开始Dijkstra也会超时。

实测，走到4步再bfs都是可以的。但是4步和10步时间相差不大。

### 代码

```python
import collections


class Solution(object):
    def minKnightMoves(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        def getClosePoint():
            threshold = 4
            if abs(x) + abs(y) <= threshold:
                return [(0, 0, 0)]

            result = []
            steps = 0
            level = [(0, 0)]
            visited = {(0, 0)}
            while level:
                steps += 1
                new_level = []
                min_dist = float("inf")
                for m, n in level:
                    for k in range(8):
                        next_m, next_n = m + offset[k][0], n + offset[k][1]
                        if (next_m, next_n) in visited: continue
                        visited.add((next_m, next_n))
                        if abs(next_m - x) + abs(next_n - y) == min_dist:
                            new_level.append((next_m, next_n))                        
                        elif abs(next_m - x) + abs(next_n - y) < min_dist:
                            min_dist = abs(next_m - x) + abs(next_n - y)
                            new_level = [(next_m, next_n)]
                    
                for m, n in new_level:
                    if abs(m - x) + abs(n - y) <= threshold:
                        result.append((steps, m, n))

                if result:
                    return result
                level = new_level

        dist = collections.defaultdict(lambda: float("inf"))
        dist[0, 0] = 0
        offset = [[2, 1], [2, -1], [1, 2], [1, -2], [-1, 2], [-1, -2], [-2, 1], [-2, -1]]
        pq = getClosePoint()
        while pq:
            d, i, j = heapq.heappop(pq)
            if d > dist[(i, j)]: continue
            if i == x and j == y: return d
            for k in range(8):
                next_i, next_j = i + offset[k][0], j + offset[k][1]
                if d + 1 < dist[(next_i, next_j)]:
                    dist[(next_i, next_j)] = d + 1
                    heapq.heappush(pq, (d + 1, next_i, next_j))
        return -1
```