
## 方法一 - 排序并合并区间
#### 说明：
 - 如果我们按照区间的 start 大小排序，那么在这个排序的列表中可以合并的区间一定是连续的。
#### 效率：
 > Runtime: 100 ms, faster than 72.61% of Python3 online submissions for Merge Intervals.
 > Memory Usage: 15.7 MB, less than 6.52% of Python3 online submissions for Merge Intervals.
#### 代码：
```Python
from typing import List
import operator


class Solution:

    def merge(self, intervals: List[List[int]]) -> List[List[int]]:

        # 首先按照区间最小值排序
        intervals.sort(key=operator.itemgetter(0))

        # 目标区间索引值
        target_idx = 0

        # 开始选取候选区间，和目标区间进行对比
        for i in range(1, len(intervals)):

            # 候选区间的开始值小于等于目标区间的结束值，则说明两区间有重合部分
            if intervals[i][0] <= intervals[target_idx][1]:
                # 更新目标区间结束值，结束值为两区间结束值中的最大值（合并区间）
                intervals[target_idx][1] = max(intervals[i][1], intervals[target_idx][1])
                # 标记候选区间为可舍弃（在不影响当前遍历的情况下）
                intervals[i] = []
            # 否则，两区间不重合
            else:
                # 更新目标区间索引值（设置新的目标区间为当前的候选区间）
                target_idx = i

        # 返回原数组集合中不为空数组的集合
        return [interval for interval in intervals if interval]
```

## 方法二 - 优化 - 使用指针 - 原地修改
#### 说明：
 - 与方法一基本一致，区别在使用指针记录候选区间位置，原地修改数组
#### 效率：
 > Runtime: 100 ms, faster than 72.61% of Python3 online submissions for Merge Intervals.
 > Memory Usage: 15.8 MB, less than 6.52% of Python3 online submissions for Merge Intervals.
#### 代码：
```Python
from typing import List
import operator


class Solution:

    def merge(self, intervals: List[List[int]]) -> List[List[int]]:

        # 首先按照区间最小值排序
        intervals.sort(key=operator.itemgetter(0))

        size = len(intervals)
        # 目标区间索引值
        target_idx = 0
        # 候选区间索引值
        candidate_idx = 1

        # 目标区间与候选区间进行对比
        while candidate_idx < size:
            # 候选区间的开始值小于等于目标区间的结束值，则说明两区间有重合部分
            if intervals[candidate_idx][0] <= intervals[target_idx][1]:
                # 更新目标区间结束值，结束值为两区间结束值中的最大值（合并区间）
                intervals[target_idx][1] = max(intervals[candidate_idx][1], intervals[target_idx][1])
                # 移除合并了的候选区间，缩小size
                intervals.pop(candidate_idx)
                size -= 1
            # 否则，两区间不重合
            else:
                # 更新目标区间索引值（设置新的目标区间为当前的候选区间）
                target_idx = candidate_idx
                # 更新候选区间索引值
                candidate_idx += 1

        return intervals
````