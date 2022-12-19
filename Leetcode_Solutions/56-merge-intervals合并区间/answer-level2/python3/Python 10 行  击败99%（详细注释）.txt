24ms 14mb
时间O(n) 空间O(n)
```python
class Solution(object):
    def merge(self, intervals):
        if not intervals : return []

        # 排序数组，因为题目没有说有序无序，所以事先排序一下
        intervals.sort()
        res = [intervals[0]]

        for i in range(len(intervals)):
            # 第一种情况，两个相邻区间不重复，直接加入数组 （[1,3],[4,5]）
            if intervals[i][0] > res[-1][1]:
                res.append(intervals[i])
            
            elif intervals[i][0] <= res[-1][1]:
                #第二种情况，区间重复，并且需要修改原区间（[1,4],[4,5]）
                if intervals[i][1] > res[-1][1]:
                    res[-1][-1] = intervals[i][1]
                #第三种情况，区间重复，但不需修改原数组（[1,6],[4,5]）
        return res                             
```
更新
```python
class Solution(object):
    def merge(self, intervals):
        intervals.sort(); res = []
        for i in range(len(intervals)):
            if not res or intervals[i][0] > res[-1][1]:
                res.append(intervals[i])
            else: res[-1][-1] = max(intervals[i][1], res[-1][1])
        return res


```
