```
class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervals.sort()
        return not any(intervals[i][1]>intervals[i+1][0] for i in range(len(intervals)-1))
```
