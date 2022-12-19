### 解题思路
只需要搞清楚怎么判断重叠区间:
当某个区间的右边界大于等于待插入的区间的左边界，以及该区间的左边界要小于等于待插入区间的右边界。
我们称这俩个区间是重叠区间。
剩下的工作只需要找出全部与待插入区间满足上述条件的区间集合即可。
### 代码

```python3
class Solution:
    def insert(self, intervals: list, newInterval: list) -> list:
        overlap_intervals, result = [], []
        for i in range(len(intervals)):
            if intervals[i][1] >= newInterval[0] and intervals[i][0] <= newInterval[1]:
                overlap_intervals.append(i)
        if len(overlap_intervals) == 0:
            intervals.append(newInterval)
            intervals.sort(key = lambda x:x[0])
            return intervals
        merge_intervals = [min(intervals[overlap_intervals[0]][0],newInterval[0]),
                           max(intervals[overlap_intervals[-1]][1],newInterval[1])
                           ]
        for i in range(overlap_intervals[0]):
            result.append(intervals[i])
        result.append(merge_intervals)
        for i in range(overlap_intervals[-1]+1,len(intervals)):
            result.append(intervals[i])
        return result
```