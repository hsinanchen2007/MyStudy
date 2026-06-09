### 代码
```python3
class Solution:
    def insert(self, intervals, newInterval):
        if not len(intervals):
            return [newInterval]

        # 二分查找
        i, j = 0, len(intervals) - 1
        while i <= j:
            mid = (i + j) // 2
            # 如果某个区间的开始和新区间的开始一样
            if intervals[mid][0] == newInterval[0]:
                intervals[mid][1] = max(intervals[mid][1], newInterval[1])
                break
            elif intervals[mid][0] > newInterval[0]:
                j = mid - 1
            else:
                i = mid + 1

        # 没有找到一样的，把new根据new[0]插入
        if i > j:
            intervals.insert(i, newInterval)

        # 构造答案
        res = []

        last = intervals[0][0] - 1
        for i in range(len(intervals)):
            if last < intervals[i][0]:
                res.append([intervals[i][0], intervals[i][0]])
                last = intervals[i][0]
            if last < intervals[i][1]:
                res[-1][1] = intervals[i][1]
                last = intervals[i][1]
        return res
```

### 思路
res　是答案数组

开始构造答案时，intervals是一个按区间开始时间递增的list

我们要的最后答案数组一定满足“从左到右的数字递增”，如
> 示例1的答案是 [[1,5],[6,9]]    
> 其中 1<5<6<9
根据这个性质，用变量last保留上一个放入res的数字

在循环体中，对于第i个区间, 他的开始时间intervals[i][0]能出现在res中的条件是：
   intervals[i][0] > last
也就是说，在res中，如果i区间的开始时间比上一个区间的结束时间大,就开一个新区间,同时更新last

如果结束时间比last大，就把最后一个区间的结束时间更新