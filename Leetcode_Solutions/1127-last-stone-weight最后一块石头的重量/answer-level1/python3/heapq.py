* 执行用时 : 52 ms, 在Last Stone Weight的Python3提交中击败了49.25% 的用户
* 内存消耗 : 13.3 MB, 在Last Stone Weight的Python3提交中击败了100.00% 的用户

```
class Solution:
    def lastStoneWeight(self, stones):
        import heapq
        heap = []
        for i in stones:
            heapq.heappush(heap, i*-1)
        left_stones = len(stones)
        while left_stones > 1:
            first = heapq.heappop(heap)
            second = heapq.heappop(heap)
            if first != second:
                heapq.heappush(heap, first-second)
                left_stones -= 1
            else:
                left_stones -= 2
        if left_stones == 1:
            return heapq.heappop(heap) * (-1)
        else:
            return 0


print(Solution().lastStoneWeight([10, 11, 12]))
print(Solution().lastStoneWeight([2, 2]))
```