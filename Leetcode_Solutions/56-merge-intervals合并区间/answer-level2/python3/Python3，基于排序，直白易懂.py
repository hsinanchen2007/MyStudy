```Python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        intervals.sort(key=lambda x: x[0])
        res = []
        period_start, period_end = intervals[0]
        for start, end in intervals:
            if start > period_end:
                res.append([period_start, period_end])
                period_start, period_end = start, end
            else:
                period_end = max(period_end, end)
        res.append([period_start, period_end])
        return res
```
