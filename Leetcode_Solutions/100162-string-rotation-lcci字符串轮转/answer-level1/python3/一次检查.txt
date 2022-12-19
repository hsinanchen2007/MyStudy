### 解题思路
S1和S2是旋转的关系，首先长度必须相等，其次将其中任意一个进行+=操作，另一个字符串必定在这个新的字符串中

### 代码

```python3
class Solution:
    def isFlipedString(self, s1: str, s2: str) -> bool:
        if len(s1)!=len(s2):
            return False
        s2=s2+s2
        if s1 not in s2:
            return False
        else:
            return True
            
```