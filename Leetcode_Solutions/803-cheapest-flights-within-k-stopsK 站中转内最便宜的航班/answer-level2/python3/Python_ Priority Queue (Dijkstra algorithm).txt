### 解题思路
此题于 dijkstra algorithm 十分相似，唯一的不同是规定了经停数量。所以我们要做的是在确保还能经停的情况下，才能往优先队列里放。

### 代码

```python
import queue
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        dic = {}
        for f, t, cost in flights:
            if f not in dic:
                dic[f] = {t: cost}
            else:
                dic[f][t] = cost
        q = queue.PriorityQueue()
        q.put((0, src, K))
        while not q.empty():
            pre, f, k = q.get()
            if f == dst: return pre
            if k >=0:
                for t in dic.get(f, []):
                    q.put((pre + dic[f][t], t, k-1))
        return -1
```