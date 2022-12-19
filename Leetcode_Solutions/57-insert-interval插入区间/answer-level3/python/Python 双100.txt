![image.png](https://pic.leetcode-cn.com/5220c5307f4328a36b66a7568ca22599cc579fa9928f3d620d02edd4c7413b05-image.png)
原地修改，节省空间
先找到第一个与待插入重叠的区间， 向后扩大区间直到没有重叠区域
最后删除所有曾重叠的子区间，插入最终新增的区间
```python
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        # 初始状况判断
        if not newInterval:
            return intervals
        if not intervals:
            return [newInterval]
        # 已经是起点有序的了
        i = 0
        intervalsLen = len(intervals)
        while i < intervalsLen and intervals[i][1] < newInterval[0]:
            i += 1
        # 保存删除之前的位置，最后在这个位置上插入
        tempI = i
        while i < intervalsLen and intervals[i][0] <= newInterval[1]:
            newInterval[0] = min(newInterval[0], intervals[i][0])
            newInterval[1] = max(newInterval[1], intervals[i][1])
            i += 1
        else:
            del intervals[tempI:i]
            intervals.insert(tempI, newInterval)
        return intervals
```