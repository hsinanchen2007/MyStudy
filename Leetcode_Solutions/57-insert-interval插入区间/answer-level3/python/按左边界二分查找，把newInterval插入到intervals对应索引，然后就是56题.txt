### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """

        def left_bs(arr, t):
            s, e = 0, len(arr)
            while s < e:
                m = s + (e - s) / 2
                if arr[m][0] <= t:
                    s = m + 1
                else:
                    e = m
            return s

        res = []
        pos = left_bs(intervals, newInterval[0])
        intervals.insert(pos, newInterval)
        i, n = 0, len(intervals)

        while i < n:
            l, r = intervals[i]
            while i < n - 1 and intervals[i + 1][0] <= r:
                r = max(r, intervals[i + 1][1])
                i += 1
            res.append([l, r])
            i += 1
        return res
```