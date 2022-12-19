```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if(intervals == []):
            return []
        length = len(intervals)
        if(length == 1):
            return intervals
        res = []
        intervals.sort()
        start = intervals[0][0]
        end = intervals[0][1]
        for each in intervals[1:]:
            if(end >= each[0] and start <= each[1]):
                start = min(start, each[0])
                end = max(end, each[1])
            else:
                res.append([start, end])
                start = each[0]
                end = each[1]
        res.append([start, end])
        return res
```
