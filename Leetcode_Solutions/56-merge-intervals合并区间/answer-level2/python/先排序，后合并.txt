按照列表每一个子列表的第一个元素对列表的所有元素进行排序。然后对相邻两个子元素进行两两比较。

假设两个相邻的子元素分别为 `[x1, y1]` 和 `[x2, y2]`，如果该区间可合并必须满足条件 `y1 >= x2`。

若该区间可合并，合并结果可能有两种：

1. 当 `y1 < y2` 时，合并结果为 `[x1, y2]`
2. 当 `y1 >= y2` 时，合并结果为 `[x1, y1]`

```python
class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        length = len(intervals)
        
        if length <= 1:
            return intervals
        
        intervals.sort()
        res = list()
        
        for i in range(length - 1):
            left = intervals[i]
            right = intervals[i + 1]
            
            if left[1] >= right[0]:
                # 区间可合并
                if left[1] < right[1]:
                    new_list = [left[0], right[1]]
                else:
                    new_list = [left[0], left[1]]
                intervals[i + 1] = new_list
            else:
                res.append(left)
                
        res.append(intervals[-1])
        return res
```