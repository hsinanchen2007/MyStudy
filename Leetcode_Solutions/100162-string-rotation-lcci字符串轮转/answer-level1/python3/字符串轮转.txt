
### 代码
```python
class Solution:
    def isFlipedString(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):return False
        s1 = s1+s1
        if s2 in s1:return True
        return False
```
```
class Solution:
    def isFlipedString(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):return False
        if not s1 and not s2:return True 
        le = len(s1)
        for i in range(le):
            if s1[i:]+s1[:i] == s2: return True
        return False
```
