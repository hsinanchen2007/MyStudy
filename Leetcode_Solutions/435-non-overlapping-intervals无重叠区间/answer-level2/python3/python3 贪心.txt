### 解题思路
此处撰写解题思路

### 代码

```python
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0
        # 区间个树
        intervalsLen = len(intervals)
        # 按照区间结尾排序
        intervals.sort(key=lambda x: x[1])
        # 第一个区间的末尾
        curEnd = intervals[0][1]
        # 结果计数
        count = 1
        for i in intervals:
            # 第一个肯定不符合，后面的在末尾小的里面挑满足区间开始大于上一个区间末尾的
            if i[0] >= curEnd:
                # 满足则区间计数加一，更新区间末尾
                count += 1
                curEnd = i[1]
        return intervalsLen - count
```