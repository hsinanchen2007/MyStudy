### 解题思路
先对开会起始时间进行排序，遍历每个会议，如果不能安排下就开新的房间

### 代码

```python3
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        rooms=[]
        intervals.sort(key=lambda x:x[0] )
        for start,end in intervals:
            iFind=False
            for i,(s,e) in enumerate(rooms):
                if start>=e:
                    rooms[i]=[start,end]
                    iFind=True
                    break
            if not iFind:
                rooms.append([start,end])
        return len(rooms)


                
```