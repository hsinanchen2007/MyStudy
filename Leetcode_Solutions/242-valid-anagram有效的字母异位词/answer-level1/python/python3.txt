### 解题思路
此处撰写解题思路

### 代码

```python []
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        for x in set(s):
            if s.count(x) != t.count(x):
                return False
        return True
```


```python3 []
from collections import Counter
class Solution:

    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)
```