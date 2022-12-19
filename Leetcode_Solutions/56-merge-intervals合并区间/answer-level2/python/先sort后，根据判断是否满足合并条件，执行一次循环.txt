执行用时 : 92 ms , 在所有 Python 提交中击败了 72.46% 的用户 内存消耗 : 14 MB , 在所有 Python 提交中击败了 100.00% 的用户
```
def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        if len(intervals) == 0:
            return intervals
        intervals = sorted(intervals, key=lambda x: x[0])
        res = []
        start = intervals[0][0]
        end = intervals[0][1]
        for interval in intervals[1:]:
            # 判断是否符合合并条件
            if end >= interval[0]: #符合 例如[1, 3], [2, 6], end=3 > intervel[0]=2 
                end = interval[1] if interval[1] > end else end # 针对 [1, 4], [2, 3]这种情况，选择end中较大的那个
            else:
                res.append([start, end])
                start = interval[0]
                end = interval[1]
        res.append([start, end])
        return res
```
