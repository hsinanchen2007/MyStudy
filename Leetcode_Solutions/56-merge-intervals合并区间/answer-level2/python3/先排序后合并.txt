```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) == 0:
            return []
        
        if len(intervals) == 1:
            return intervals

        sorted_intervals = list(sorted(intervals, key=lambda x: (x[0],x[1])))
        
        res = [x for x in sorted_intervals[0]]
        for xx in range(1, len(sorted_intervals)):
            if res[-2] <= sorted_intervals[xx][0] <= res[-1] and sorted_intervals[xx][1] >= res[-1]:
                res[-1] = sorted_intervals[xx][1]
            elif res[-2] <= sorted_intervals[xx][0] <= res[-1]:
                continue
            else:
                res.append("end")
                res.append(sorted_intervals[xx][0])
                res.append(sorted_intervals[xx][1])
        
        res.append("end")
        re_res = []
        tmp_ = []
        for x in res:
            if x != "end":
                tmp_.append(x)
            else:
                re_res.append(tmp_)
                tmp_ = []
        
        return re_res
```
