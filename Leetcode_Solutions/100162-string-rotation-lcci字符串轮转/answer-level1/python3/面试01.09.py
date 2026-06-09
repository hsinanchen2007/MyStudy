### 解题思路
字符串旋转后*2，中间包含未旋转字符串  abcd->dabc *2->d`abcd`abc


### 代码

```python3
class Solution:
    def isFlipedString(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        else:
            ss = s2 + s2
            return s1 in ss
```