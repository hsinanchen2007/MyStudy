### 解题思路
使用Counter计数

### 代码

```python3
from collections import Counter
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        temp = Counter(nums)

        for i in temp:

            if temp[i] >= 2:
                return i
                
        return -1
```