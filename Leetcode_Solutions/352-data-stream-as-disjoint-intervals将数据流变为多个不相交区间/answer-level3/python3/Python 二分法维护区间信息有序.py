
![image.png](https://pic.leetcode-cn.com/5d9f8fcb9aeae16ccd6def36f3a85eef7d70d340c195b3f2adfd36b87dfc969f-image.png)



```

'''
把区间信息按照区间起点有序维护
插入数据时候二分法找离数值最近的区间，进行合并区间的操作
'''

from typing import List
from sortedcontainers import SortedDict
class SummaryRanges:

    def __init__(self):
        self.m = SortedDict()

    def addNum(self, val: int) -> None:
        idx = self.m.bisect_right(val)
        n = len(self.m)
        if idx >= 0 and idx < n and idx-1 >= 0:
            s1, e1 = self.m.keys()[idx-1], self.m.values()[idx-1]
            s2, e2 = self.m.keys()[idx], self.m.values()[idx]

            if e1 == val - 1 and s2 == val + 1:
                self.m.pop(s2)
                self.m[s1] = e2
                return

        if idx >= 0 and idx < n:
            s2, e2 = self.m.keys()[idx], self.m.values()[idx]
            if s2 == val + 1:
                self.m.pop(s2)
                self.m[val] = e2
                return
            if val >= s2 and val <= e2:
                return

        if idx-1 >= 0 and idx-1 < n:
            s1, e1 = self.m.keys()[idx - 1], self.m.values()[idx - 1]
            if e1 == val - 1:
                self.m[s1] = val
                return
            if val >= s1 and val <= e1:
                return

        self.m[val] = val

    def getIntervals(self) -> List[List[int]]:
        return [[k, v] for k, v in self.m.items()]
```
