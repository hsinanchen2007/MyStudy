每次合并之前，intervals增加一个辅助元素['inf','inf'],为了把所有的原始元素进行操作
```Python []
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])
        flag = True
        while flag:
            i, flag, ret = 0, False, list()
            intervals.append([float('inf'),float('inf')])
            while i < len(intervals) - 1:
                if intervals[i+1][1] < intervals[i][1]:
                    ret.append(intervals[i])
                    i, flag = i + 2, True
                elif intervals[i+1][0] <= intervals[i][1]:
                    ret.append([intervals[i][0],intervals[i+1][1]])
                    i, flag = i + 2, True
                else:
                    ret.append(intervals[i])
                    i += 1
            intervals = ret
        return intervals
```

