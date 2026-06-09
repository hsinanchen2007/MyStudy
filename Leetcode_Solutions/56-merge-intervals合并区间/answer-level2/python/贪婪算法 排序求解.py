### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        intervals.sort(key=lambda x:x[0])
        results = []
        for current in intervals:
            if len(results)==0 or current[0] > results[-1][1]:  # 如果是第一个区间,或者两个区间无重叠(当前区间的起点 大于前一个区间的终点)
                results.append(current)
            else:
                results[-1][1] = max(results[-1][1], current[1])  # 更新前一个区间的结束位置
        return results
```

排序的 时间复杂度是o(nlogn)
遍历复杂度是o(n)

所以总的是o(nlogn)
