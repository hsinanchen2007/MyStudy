### 解题思路
使用collections模块的Counter,执行用时48ms,内存消耗13.4MB

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        from collections import Counter
        return Counter(s) == Counter(t)
```