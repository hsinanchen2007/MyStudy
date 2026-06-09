从左到右，可合并则合并，可排序则排序。
```
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        intervals.append(newInterval)
        if len(intervals) < 1:
            return intervals
        res = intervals
        idx = len(res) - 2
        j = len(res) - 1
        while idx >= 0:
            if  not (res[j][0] > res[idx][1] or res[j][1] < res[idx][0]):
                res[idx] = [min(res[j][0],res[idx][0]),max(res[j][1],res[idx][1])]
                del res[j]    
                j = idx
            else:
                if res[j][0] < res[idx][0]:
                    temp = res[idx]
                    res[idx] = res[j]
                    res[j] = temp
                    j = idx
                else:
                    break
            idx -= 1
        return res
```
