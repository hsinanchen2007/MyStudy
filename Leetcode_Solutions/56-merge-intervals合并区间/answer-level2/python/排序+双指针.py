### 解题思路

### 代码

```python
class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]

        思路：现对区间进行排序再遍历区间
        """
        if len(intervals)<=1:
            return intervals
        intervals.sort()
        n = len(intervals)
        begin = 0
        end = 1
        res = []
        while end<n:
            beginLeft,beginRight = intervals[begin]
            endLeft, endRight = intervals[end]
            if beginRight>=endLeft:
                intervals[begin][1] = max(beginRight,endRight)
                end+=1
            else:
                res.append(intervals[begin])
                begin = end
                end = begin+1
        res.append(intervals[begin])
        return res


```