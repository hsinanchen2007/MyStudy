```
class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        """
           首先对所有的区间按照起始点进行排序，排完序再使用二分查找的方法
           
        """
        from bisect import bisect_left
        size = len(intervals)
        if size == 0:
            return []
        if size == 1:
            return [-1]
        
        index_intervals = [(value[0],value[1],i) for i, value in enumerate(intervals)]

        sorted_index_intervals = sorted(index_intervals, key=lambda x: x[0])
        ans = []
        for interval in intervals:
            # 观察该区间的终点能否插入sorted_index_intervals
            i = bisect_left(sorted_index_intervals, (interval[1], float("-inf"), 0))
            if i == len(sorted_index_intervals):
                ans.append(-1)
            else:
                ans.append(sorted_index_intervals[i][-1])  

        return ans
```
