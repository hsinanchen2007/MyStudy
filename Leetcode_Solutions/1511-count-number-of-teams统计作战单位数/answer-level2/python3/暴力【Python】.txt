### 思路

**暴力**

```
三层循环，暴力求解。
因为数据 n 是 [1, 200]，所以不会 LTE。
```

**时间复杂度:** O(n^3)
**空间复杂度:** O(1)

##### Python3代码

```python
from typing import List

class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        count = 0
        for i in range(n-2):
            for j in range(i+1, n-1):
                for k in range(j+1, n):
                    if rating[i] < rating[j]:
                        if rating[j] < rating[k]:
                            count += 1
                    elif rating[i] > rating[j]:
                        if rating[j] > rating[k]:
                            count += 1
        return count
```

### GitHub链接

[Python](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/1395-Count-Number-of-Teams/1395.py)