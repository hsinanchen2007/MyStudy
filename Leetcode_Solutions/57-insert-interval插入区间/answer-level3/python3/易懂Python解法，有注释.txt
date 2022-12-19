如下：
```python []
class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        result = []
        tmp = newInterval
        for i in range(len(intervals)):
            current = intervals[i]
            if tmp[0] > current[1]:
                # 如果 newInterval 的左值大于 item 的右值
                result.append(current)
            elif tmp[1] < current[0]:
                # 如果 newInterval 的右值小于 item 的左值，直接退出循环
                return result + [tmp] + intervals[i:]
            else:
                # 碰到要插入的区间，保存作为临时值
                little = min(current[0], tmp[0])
                big = max(current[1], tmp[1])
                tmp = [little, big]

        return result + [tmp]
```

