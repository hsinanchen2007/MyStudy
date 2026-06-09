### 解题思路
应用heapify()先将nums堆化，然后使用nlargest()返回所求的值

### 代码

```python3
from heapq import *
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heapify(nums)
        return nlargest(k,nums)[-1]
```