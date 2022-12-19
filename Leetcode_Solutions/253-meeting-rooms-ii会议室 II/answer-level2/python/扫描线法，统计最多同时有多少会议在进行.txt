### 解题思路
用扫描线法可以很容易得到该题的解。每当有会议加入时，meetings 加1， 每当有会议退出时，meetings 减1。求出meetings的最大值即可。

### 代码

```python
class Solution(object):
    def minMeetingRooms(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        events = []
        for inter in intervals:
            events.append([inter[0], 1])
            events.append([inter[1], -1])
        events.sort()
        meetings = 0
        rooms = 0
        for e in events:
            if e[1] > 0:
                meetings += 1
            else:
                meetings -= 1
            rooms = max(rooms, meetings)
        return rooms
```