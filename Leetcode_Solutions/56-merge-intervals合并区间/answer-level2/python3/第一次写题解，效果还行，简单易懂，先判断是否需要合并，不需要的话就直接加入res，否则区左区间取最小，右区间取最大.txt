```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        res = []
        intervals.sort()
        num = len(intervals)-1
        i = 1
        res.append(intervals[0])
        
        while i <= num:
            top = res[-1]
            if max(top) < min(intervals[i]) or min(top) > max(intervals[i]):
                res.append(intervals[i])
            else:
                res.pop()
                res.append([min(top[0], intervals[i][0]), max(top[1], intervals[i][1])])
            i += 1
        return res
```
