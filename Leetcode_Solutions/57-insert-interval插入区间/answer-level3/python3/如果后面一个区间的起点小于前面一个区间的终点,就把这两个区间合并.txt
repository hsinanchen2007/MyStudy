先插入到数组里,再按照起始点排序
然后用贪心算法,如果后面一个区间的起点小于前面一个区间的终点,就把这两个区间合并
```
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res=[]
        intervals.append(newInterval)
        intervals.sort()
        t=intervals[0]
        for i in range(1,len(intervals)):
            if intervals[i][0]>t[1]:
                res.append(t)
                t=intervals[i]
            else:
                t[1]=max(t[1],intervals[i][1])
        res.append(t)
        return res
```
