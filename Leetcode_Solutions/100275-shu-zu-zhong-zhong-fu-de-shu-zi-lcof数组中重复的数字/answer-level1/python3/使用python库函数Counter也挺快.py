### 代码

```python3
from collections import Counter
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        count = Counter(nums)
        for i in count.keys():
            if count[i] > 1:
                return i
```