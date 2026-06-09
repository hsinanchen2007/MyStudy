```
class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        intervals.append(newInterval)
        intervals.sort()
        if len(intervals)<2:
            return intervals
        res=[intervals[0]]
        for i in range(1,len(intervals)):
            if intervals[i][0]<=res[-1][1]<intervals[i][1]:
                res[-1]=[res[-1][0],intervals[i][1]]
            elif intervals[i][0]>res[-1][1]:
                res.append(intervals[i])
        return res
```
