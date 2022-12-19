```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if intervals==[]:return []
<!-- python排序，默认是对数组第一个数字进行排序。 -->
        intervals.sort()
<!-- 结果集，初值为排序后第一个区间 -->
        res = [[intervals[0][0],intervals[0][1]]]
<!-- 进入循环，发现有能覆盖之前区间的，覆盖掉，注意以下里面判断条件的细节 -->
        for i in range(1,len(intervals)):
            if intervals[i][0]<=res[-1][1] :
                if intervals[i][1]>res[-1][1]:
                    k=res.pop()
                    res.append([k[0],intervals[i][1]])
                    continue
                else:continue
            res.append([intervals[i][0],intervals[i][1]])
        return res
                
```
