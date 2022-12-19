## 思路
1. 类似树的问题，所以递归来看，也比较直白；
2. 枚举分割位置`i`:进一步判断 s1[:i], s1[i:]与s2是否交叉或非交叉；

## Solutions
```python
class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        if sorted(s1) != sorted(s2):
            return False
        if len(s1) == 1:
            if s1 == s2:
                return True
            else:
                return False
        if not len(s1):
            return True
        l = len(s1)
        for ind in range(len(s1)-1):
            if self.isScramble(s1[:ind+1], s2[:ind+1]) and self.isScramble(s1[ind+1:], s2[ind+1:]):
                return True
            if self.isScramble(s1[:ind+1], s2[l-ind-1:]) and self.isScramble(s1[ind+1:], s2[:l-ind-1]):
                return True
        return False
```