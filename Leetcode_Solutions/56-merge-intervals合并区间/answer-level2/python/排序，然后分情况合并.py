1. 区间排序，首先按照左边界排序，然后按照右边界排序
2. 用一个res数组装结果，遍历参数数组，判断res数组的最后一个区间是否可以和当前区间合并
3. 至于判断两个区间是否可以合并，排序之后两个相邻区间只可能有以下三种情况，分别判断即可。

![56-1.png](https://pic.leetcode-cn.com/08ff988e9d2a9baa66b1459b2e07a7f33a2298f195a284a57bb2ea8528113a37-56-1.png)
**代码**：
```python
class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        if not intervals:return []
        intervals.sort()
        res = [intervals[0]]
        for i in range(1, len(intervals)):
            # 交叉
            if res[-1][1] >= intervals[i][0] and res[-1][1] <= intervals[i][1]:
                res[-1][1] = intervals[i][1]
            # 在内部
            elif res[-1][1] >= intervals[i][1]:
                continue
            # 在外部，不重叠，直接加入
            else:
                res.append(intervals[i])
        return res
```
