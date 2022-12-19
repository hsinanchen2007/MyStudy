### 解题思路

标准库用法展示，哈哈哈

### 代码

```python3
from heapq import nsmallest


class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        return nsmallest(k, arr)
```