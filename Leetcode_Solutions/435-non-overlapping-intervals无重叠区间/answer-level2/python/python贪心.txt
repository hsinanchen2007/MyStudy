类似最大执行任务数问题。
```
class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        n = len(intervals)
        if n <= 1:
            return 0
        # 等价于执行任务的最大数量
        # 按照区间结束位置进行排序
        intervals = sorted(intervals, key = lambda x:x[1])
        print(intervals)
        # i:当前索引数，排序后第一个肯定要执行，从第一个开始遍历。
        # cur_end：当前区间的结尾值，初始化为排序后第一个区间的结尾值。
        # count:已计入区间数，初始化为1。
        i = 1
        cur_end = intervals[0][1]
        count = 1
        while i < n:
            # 如果第i个区间的开始值大于当前结尾值，则将其加入计数区间，更新cur_end。
            if intervals[i][0] >= cur_end:
                count += 1
                cur_end = intervals[i][1] 
                i += 1
            # 否则，继续查看下一个区间，不更新count和cur_end。
            else:
                i += 1
        # 记入总区间的区间个数为count，总区间个数为n，返回差值。
        return n-count
            
```
