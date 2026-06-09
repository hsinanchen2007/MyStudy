```
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []
        intervals = [newInterval] + intervals
        n = len(intervals)
        intervals = sorted(intervals)
        i = 0
        while(i < n):
            left = intervals[i][0]
            right = intervals[i][1]
            while(i < (n-1) and right >= intervals[i+1][0]):
                right = max(right, intervals[i+1][1])
                i += 1
            res.append([left, right])
            i += 1
        return res
```
