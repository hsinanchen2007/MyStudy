### 解题思路
贪心，每次选择已经开始的最先结束的会议参加

### 代码

```python3
import heapq

class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events = sorted(events) # 按会议开始时间排序会议
        i = 0
        heap = [] # 存储当前已经开始的会议的结束时间，并用堆进行排序
        rlt = 0
        while i < len(events) or len(heap) != 0:
            # 如果没有已经开始的会议，那么跳到最近会开始的会议时刻开始遍历
            if len(heap) == 0:
                s = events[i][0]
            else:
                s += 1
            # 将最新能参加的会议加入队列
            while i < len(events) and events[i][0] == s:
                heapq.heappush(heap, events[i][1])
                i += 1
            # 选取堆中还没有结束的最先结束的会议参加
            while len(heap) != 0:
                val = heapq.heappop(heap)
                if val >= s:
                    rlt += 1
                    break
                    
        return rlt       
```