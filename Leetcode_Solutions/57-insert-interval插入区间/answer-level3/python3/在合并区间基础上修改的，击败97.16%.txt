```
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        intervals.append(newInterval)
        intervals=sorted(intervals)
        res=[]
        n=len(intervals)
        i=0
        while(i<n):
            left=intervals[i][0]
            right=intervals[i][1]
            while(i<n-1 and intervals[i+1][0]<=right):
                i=i+1
                right=max(intervals[i][1],right)
            res.append([left,right])
            i=i+1
        return res
```
思路：
1. 将新区间插入到区间列表中，并按照下界进行排序
2. 按照合并区间进行合并

由于给定的列表是排好序并无重叠的，所以为最好情况复杂度
