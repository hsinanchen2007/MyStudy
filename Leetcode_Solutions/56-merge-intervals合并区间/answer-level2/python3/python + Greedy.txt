```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # Time complexity : O(NlogN)
        # Space complexity: O(N)
        res = []
        if intervals == []: return [] # special case
        intervals.sort(key = lambda x: (x[0], x[1]))
        begin, end = intervals[0]
        for i in range(1, len(intervals)):
            if intervals[i][0] <= end:
                end = max(end, intervals[i][1])
            else:
                res.append([begin, end])
                begin, end = intervals[i]
        res.append([begin, end])
        return res
```