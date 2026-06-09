### 解题思路
- 先排序，求前缀和
- 然后二分查找

### 代码

```python
from itertools import accumulate
import bisect


class Solution:
    def maxNumberOfApples(self, arr: List[int]) -> int:
        return bisect.bisect(list(accumulate(sorted(arr))), 5000)

```