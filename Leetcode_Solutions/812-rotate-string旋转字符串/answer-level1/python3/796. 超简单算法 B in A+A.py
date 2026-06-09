### 解题思路
1. 先判断长度是否相等，长度不相等，如何旋转都不可能相同。
2. 如果B出现在A+A中，那么通过旋转操作得到B。

### 代码

```
class Solution:
    def rotateString(self, A: str, B: str) -> bool:
        if len(A) != len(B):
            return False
        if B in A+A:
            return True
        return False
```