先排序，按照每一个区间的较小值。
接下来遍历，只需要跟最后一个比较即可。
```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        intervals.sort()
        r = [intervals[0]]
        for i in range(len(intervals)):
            if not (intervals[i][0] > r[-1][1] or intervals[i][1] < r[-1][0]):
                r[-1] = [min(intervals[i][0],r[-1][0]),max(intervals[i][1],r[-1][1])]
            else:
                r.append(intervals[i])
        return r
```

