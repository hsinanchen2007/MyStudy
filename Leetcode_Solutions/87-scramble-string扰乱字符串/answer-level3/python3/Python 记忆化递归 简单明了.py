![image.png](https://pic.leetcode-cn.com/4939d2b871b5e81e502bb1223824b2e0c3ab6ef29286565cf81f2f082ff22867-image.png)


```
'''
两个字符串要能互相转换，要么前半部分后后半部分都能相互转换
或者s1前半部分和s2后半部分能相互转换且s1后半部分和s2前半部分能相互
转换
'''

from collections import Counter
from functools import lru_cache
class Solution:
    @lru_cache(typed=False)
    def isScramble(self, s1: str, s2: str) -> bool:
        #print(s1, s2)
        if Counter(s1) != Counter(s2):
            return False

        if len(s1) == 1:
            return s1 == s2
        elif len(s1) == 2:
            return s1 == s2 or s1 == s2[::-1]

        for mid in range(1, len(s1)):
            if (self.isScramble(s1[:mid], s2[:mid]) and self.isScramble(s1[mid:], s2[mid:])) or \
               (self.isScramble(s1[:mid], s2[-mid:]) and self.isScramble(s1[mid:], s2[:len(s1)-mid])):
                return True
        return False
```
