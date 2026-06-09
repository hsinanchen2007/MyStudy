### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isFlipedString(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        return s1 in s2+s2
```