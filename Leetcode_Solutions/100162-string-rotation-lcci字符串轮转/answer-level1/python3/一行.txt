### 解题思路
长度一致且属于其子串

### 代码

```python3
class Solution:
    def isFlipedString(self, s1: str, s2: str) -> bool:
        return len(s1) == len(s2) and s1 in s2*2
```