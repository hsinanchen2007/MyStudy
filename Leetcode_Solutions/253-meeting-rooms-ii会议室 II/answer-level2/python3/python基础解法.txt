### 解题思路
利用排序的思想，分别把开始时间和结束时间抽取出来，如果开始时间大于结束时间，说明一间会议室可以共用

### 代码

```python3
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0
        
        used_rooms = 0
        start_timing = sorted([i[0] for i in intervals])
        end_timing = sorted([i[1] for i in intervals])

        start_pointer = 0
        end_pointer = 0
        while start_pointer < len(intervals):
            if start_timing[start_pointer] >= end_timing[end_pointer]:
                used_rooms -= 1
                end_pointer += 1
            used_rooms += 1
            start_pointer += 1
        return used_rooms
```