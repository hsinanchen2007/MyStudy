### 思路

**暴力**

**时间复杂度:** O(n^2)
**空间复杂度:** O(1)

##### Python3代码

```python
from typing import List

class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        # solution one: 暴力
        res = 0
        for x in arr1:
            cnt = 0
            for y in arr2:
                if abs(x-y) <= d:
                    break
                else:
                    cnt += 1
                if cnt == len(arr2):
                    res += 1
        return res

        # solution two: 一行代码
        return sum(all(abs(a1 - a2) > d for a2 in arr2) for a1 in arr1)
```

### GitHub链接

[Python](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/1385-Find-the-Distance-Value-Between-Two-Arrays/1385.py)