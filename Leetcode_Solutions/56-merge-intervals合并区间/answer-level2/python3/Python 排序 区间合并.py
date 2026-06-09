```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        # 去除重叠区间
        # 第一步，按照start升序排列
        intervals.sort(key = lambda x: x[0])
        # 第二步
        start = intervals[0][0]
        end   = intervals[0][1]
        ret   = []
        for idx in range(1, len(intervals)):
            curStart, curEnd = intervals[idx]
            # 如果有重叠，则更新end为更长的哪一个
            if curStart <= end:
                end = max(end, curEnd)
            else:
            # 如果没有重叠，则添加合并后区间，并更新下一个起点和终点
                ret.append([start, end])
                start = curStart
                end   = curEnd
        # 不要忘了最后这部，还剩下一组没有添加到
        else:
            ret.append([start, end])
        return ret
```