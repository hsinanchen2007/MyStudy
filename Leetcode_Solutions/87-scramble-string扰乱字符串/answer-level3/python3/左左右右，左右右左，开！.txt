### 解题思路 加@functools.lru_cache(None)何用？不加也很快
此处撰写解题思路

### [代码](https://leetcode-cn.com/problems/scramble-string/solution/di-gui-by-powcai/)

```python
import functools
class Solution:
    
    def isScramble(self, s1: str, s2: str) -> bool:
        if s1 == s2:
            return True
        if sorted(s1) != sorted(s2):
            return False
        for i in range(1, len(s1)):
            if self.isScramble(s1[:i],s2[:i]) and self.isScramble(s1[i:],s2[i:]):
                return True
            if self.isScramble(s1[:i],s2[-i:]) and self.isScramble(s1[i:],s2[:-i]):
                return True
        return False

```