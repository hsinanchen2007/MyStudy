### 解题思路
取巧，速度居然比想象的快
内存是因为生成了一个字典导致

### 代码

```python3
from collections import Counter
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        return Counter(nums).most_common(1)[0][0]
```