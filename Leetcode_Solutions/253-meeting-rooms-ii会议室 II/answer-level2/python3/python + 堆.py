```python
import heapq
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda x: (x[0], -x[1]))
        ans = 0
        heap = []
        for interval in intervals:
            while heap and interval[0] >= heap[0][0]: heapq.heappop(heap)
            heapq.heappush(heap, (interval[1], interval[0]))
            ans = max(ans, len(heap))
        return ans
```