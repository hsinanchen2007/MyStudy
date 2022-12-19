```
class Solution:
    def lastStoneWeight(self, stones) -> int:
        if stones.__len__() == 1:
            return stones[0]

        stones=[-i for i in stones]

        import heapq
        heapq.heapify(stones)
        while True:
            # max1, max2 = heapq.nlargest(2, stones)
            max1=-heapq.heappop(stones)
            max2=-heapq.heappop(stones)
            if max1 > max2:
                heapq.heappush(stones, max2 - max1)
            if stones.__len__() == 0:
                return 0
            if stones.__len__() == 1:
                return -stones[0]
```