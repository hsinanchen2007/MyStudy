![图片.png](https://pic.leetcode-cn.com/9398890d56a006c9cda987b9b78cbcb383d16688f3f123f12c73524e497da8e8-%E5%9B%BE%E7%89%87.png)

```python []
from typing import List
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals)
        result =[]
        while intervals:
            i = 1
            b = intervals[0][1]
            while i < len(intervals) and b >= intervals[i][0]:
                b = max(b,intervals[i][1])
                i+=1
            
            result.append([intervals[0][0],b])
            intervals = intervals[i:]
        return result
```
