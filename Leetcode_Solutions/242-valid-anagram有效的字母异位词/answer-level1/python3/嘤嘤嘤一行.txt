### 解题思路
取巧而已，请勿模仿 : ）

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)
```