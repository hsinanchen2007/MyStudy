### 解题思路
使用 collections.Counter的函数

### 代码

```python3
from collections import Counter
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        return list(Counter(arr).most_common(1)[0])[0]
        
```