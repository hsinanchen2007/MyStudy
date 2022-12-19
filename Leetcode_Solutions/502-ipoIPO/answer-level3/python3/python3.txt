```
import heapq as hq

class Solution:
    def findMaximizedCapital(self, k: int, W: int, Profits: List[int], Capital: List[int]) -> int:
        max_heap, min_heap = [], []
        for i in range(len(Capital)):
            if Capital[i] <= W:
                max_heap.append((-Profits[i], Capital[i]))
            else:
                min_heap.append((Capital[i], Profits[i]))
        hq.heapify(max_heap)
        hq.heapify(min_heap)
        i = 0
        while max_heap and i < k:
            W -= hq.heappop(max_heap)[0]
            while min_heap:
                tmp = hq.heappop(min_heap)
                if tmp[0] <= W:
                    hq.heappush(max_heap, (-tmp[1], tmp[0]))
                else:
                    hq.heappush(min_heap, tmp)
                    break
            i += 1
        return W
```
