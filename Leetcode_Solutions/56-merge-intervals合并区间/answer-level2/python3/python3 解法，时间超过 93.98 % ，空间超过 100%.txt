```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        
        if intervals == []: return []
        
        intervals.sort(key=lambda x:x[0])  # 先按根据每个区间的第一项对列表进行排序
        res = [intervals[0]]   # 用于保存得到的结果区间
        for i in range(1, len(intervals)):
            if intervals[i][0] <= res[-1][1]:  # 如果某个区间的最小值比结果列表中的最后一个区间的最大值小，则更新结果中的最后一个区间
                res[-1] = [res[-1][0], max(intervals[i][1], res[-1][1])]
            else:                                          # 否则，将当前区间加入结果列表中
                res.append(intervals[i])
        
        return res
```