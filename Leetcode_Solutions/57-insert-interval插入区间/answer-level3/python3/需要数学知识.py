### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        # 如果intervals为空,直接插入
        if intervals == [] :
            intervals.append(newInterval)
            return intervals
        # 如果新区间没有重合,并且位于最右端
        if newInterval[0] > intervals[-1][1] :
            intervals.append(newInterval)
            return intervals
        # 如果新区间没有重合,并且位于最左端
        if newInterval[1] < intervals[0][0] :
            intervals.insert(0,newInterval)
            return intervals
        # 如果存在重合
        path = []
        n = len(intervals)
        b = 0
        for i in range(n) :
            if self.JudgeCoincident(intervals[i - b], newInterval) :
                path.append(intervals[i - b])
                del intervals[i - b]
                b += 1
        if path == [] :
            intervals.append(newInterval)
            intervals.sort()
            return intervals
        left = newInterval[0]
        right = newInterval[1]
        if path[0][0] < left :
            left = path[0][0]
        if path[-1][1] > right :
            right = path[-1][1]
        intervals.append([left, right])
        intervals.sort()                 # 按照第一个数字进行排序
        return intervals

    def JudgeCoincident(self, interval, newInterval):
        if newInterval[0] > interval[1] or newInterval[1] < interval[0] :
            return False
        else:
            return True

```