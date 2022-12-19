### 解题思路
利用Counter解决

### 代码

```python3
from collections import Counter
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        return True if max(Counter([i for i in Counter(arr).values()]).values()) == 1 else False
```