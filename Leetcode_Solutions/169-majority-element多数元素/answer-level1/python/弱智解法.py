### 解题思路
用Counter转换为字典.
用max找到值最大的key

### 代码

```python3
from collections import Counter
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        d = Counter(nums)
        return max(d, key=d.get)

```