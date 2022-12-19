思路1：暴力法，两两比较是否重叠，双重循环
思路2：将intervals排序，这样只需判断相邻会议是否重叠即可
```
class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        if not intervals: return True
        intervals.sort()
        right = intervals[0][-1]
        for x,y in intervals[1:]:
            if x<right: return False
            else:
                right = y
        return True
```
