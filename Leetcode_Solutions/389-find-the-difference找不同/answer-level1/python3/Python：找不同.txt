### 解题思路
集合，求差

### 代码

```python3
import collections
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        return list((collections.Counter(t)-collections.Counter(s)).elements())[0]
```