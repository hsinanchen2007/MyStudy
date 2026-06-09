### 思路

**数组**

**时间复杂度:** O(n)，n 为 index 长度，nums 长度和 index 相同。
**空间复杂度:** O(n)，n 为 index 长度。

##### Python3代码

```python
from typing import List

class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        target = []
        for i in range(len(index)):
            target.insert(index[i], nums[i])  # insert(位置, 值)
        return target
```

### GitHub链接

[Python](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/1389-Create-Target-Array-in-the-Given-Order/1389.py)