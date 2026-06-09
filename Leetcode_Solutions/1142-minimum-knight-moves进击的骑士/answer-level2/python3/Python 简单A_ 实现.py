![image.png](https://pic.leetcode-cn.com/3f957e92cffb26900e1a783662dd1424066f6a1fb3fb4a9186c4c6bce4c42a13-image.png)


```
from queue import PriorityQueue
class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:
        x, y = abs(x), abs(y)
        min_heap = PriorityQueue()
        best_stat = {}

        min_heap.put((max(x, y)//2, 0, 0, 0))
        best_stat[(0, 0)] = 0

        while not min_heap.empty():
            _, payload, i, j = min_heap.get()

            if i == x and j == y:
                return payload

            for ii, jj in [(1, 2), (-1, 2), (1, -2), (-1, -2), (2, 1), (-2, 1), (2, -1), (-2, -1)]:
                new_i, new_j = i + ii, j + jj
                if (new_i, new_j) not in best_stat or payload+1 < best_stat[(new_i, new_j)]:
                    min_heap.put( (payload + max(abs(new_i-x), abs(new_j-y))//2, payload+1, new_i, new_j) )
                    best_stat[(new_i, new_j)] = payload+1
        return -1

```
