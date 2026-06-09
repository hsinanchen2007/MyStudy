```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        intervals.sort()
        start=intervals[0][0]
        end=intervals[0][1]
        res=[]
        for i in intervals:
            if start<=i[0]<=end:
                end=max(end,i[1])
            else:
                res.append([start,end])
                start=i[0]
                end=i[1]
        res.append([start,end])
        return res
```
