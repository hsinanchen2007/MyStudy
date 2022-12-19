将n右移一位异或n，检查结果是否全为1。
```
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        tmp = n^(n>>1)
        return tmp&(tmp+1) == 0
```
