### 解题思路
使用Counter类计数

### 代码

```python3
from collections import Counter
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        temp = Counter(nums)
        for i in temp:   
            if temp[i] >= math.ceil(len(nums)/2):
                return i
        return -1
```