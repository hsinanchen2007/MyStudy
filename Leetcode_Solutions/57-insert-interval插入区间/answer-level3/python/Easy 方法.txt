### 解题思路
插入新的区间到原来的数组中，然后将新数组排序。接着再一个个插入最终结果的空列表中。该合并就合并，不能合并就直接添加区间。很简单的思路。
### 代码

```python
class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        Res = []
        N = len(intervals)
        intervals +=[newInterval]
        # 先排序
        intervals.sort()
        print(intervals)
        N +=1
        Res.append(intervals[0])

        for i in range(1,N):
            last = Res[-1]
            inter = intervals[i]
            # 不能合并
            if inter[0]>last[1]:
                Res.append(inter)
            # 可以合并
            elif inter[1]>last[1] and inter[0]<=last[1]:
                Res[-1][1] = inter[1]
            elif inter[1]<=last[1] and inter[0]>=last[0]:
                continue
        return Res
```