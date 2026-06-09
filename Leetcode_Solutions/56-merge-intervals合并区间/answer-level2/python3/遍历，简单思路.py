看了答案都挺复杂的。讲一下我的思路，思路很简单。
列表排序以后，遍历列表，如果intervals[i][1]比intervals[i+1][0]大，说明有重叠，则进行合并，并删除intervals[i+1];
否则，i+=1, 往后遍历。
```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n = len(intervals)
        if n == 1:
            return intervals
        intervals = sorted(intervals)
        i = 0
        while i < len(intervals)-1:
            if intervals[i][1] >= intervals[i+1][0]:
                if intervals[i][1] < intervals[i+1][1]:
                    intervals[i][1] = intervals[i+1][1]
                del intervals[i+1]
            else:
                i += 1
        return intervals
```
