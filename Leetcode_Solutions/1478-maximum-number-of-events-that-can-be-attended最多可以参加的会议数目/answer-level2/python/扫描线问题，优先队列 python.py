### 解题思路
每一天，新开始的会议加入优先队列。
加完了之后，从队列中找出一个今天能参加的会议（同时把过期会议剔除）,结果加1.

有点类似天际线问题，关键点在于维护最小堆。

### 代码

```python
class Solution(object):
    def maxEvents(self, events):
        """
        :type events: List[List[int]]
        :rtype: int
        """
        events.sort()
        start, stop = events[0][0], max(events[i][1] for i in range(len(events)))
        pq = []
        event_idx = 0
        ans = 0
        for i in range(start, stop + 1):
            while event_idx < len(events) and events[event_idx][0] == i:
                heapq.heappush(pq, events[event_idx][1])
                event_idx += 1

            if pq:
                top_event = heapq.heappop(pq)
                while pq and pq[0] == i:
                    heapq.heappop(pq)

                ans += 1
        return ans
```