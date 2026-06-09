### 解题思路
优先队列外加贪心算法。代码如下
### 代码

```python3
class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        import heapq
        days = []
        for l in events:
            days.extend(l)
        start = min(days); end = max(days)
        # print(start, end)
        events = [(l[0], l[1]) for l in events]
        heapq.heapify(events)
        attend = []
        for i in range(start, end+1):
            while events:
                now_meeting = heapq.heappop(events)
                if now_meeting[1]<i:
                    continue
                else:
                    if now_meeting[0]<i:
                        heapq.heappush(events, (i, now_meeting[1]))
                    else:
                        if now_meeting[0] == i:
                            attend.append(i)
                            break
                        else:
                            heapq.heappush(events, now_meeting)
                            break
        return len(attend)

        

```