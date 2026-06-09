### 解题思路
heapq默认建立小顶堆，可以通过把list取反来间接建立大顶堆

### 代码

```python3
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        if len(stones) == 1: return stones[0]
        import heapq
        heap = []
        for s in stones:
            heapq.heappush(heap, -s)
        while len(heap) > 1:
            x = heapq.heappop(heap)
            if len(heap) == 0: return x
            y = heapq.heappop(heap)
            if x != y: heapq.heappush(heap, x-y)
        return 0 if len(heap) == 0 else -heap[0]
```