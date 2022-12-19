### 解题思路
Python3.6以后的字典都是有序的。

### 代码

```python []
class Solution:
    def firstUniqChar(self, s: str) -> str:
        return next((c for c, t in collections.Counter(s).items() if t == 1), ' ')
```