### 解题思路
pythonic
### 代码

```python3
from collections import Counter
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        a=Counter(s)
        b=Counter(t)
        if a==b:
            return True
        return False
        