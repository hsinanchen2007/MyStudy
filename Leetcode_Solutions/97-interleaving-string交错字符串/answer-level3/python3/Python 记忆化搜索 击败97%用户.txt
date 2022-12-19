![image.png](https://pic.leetcode-cn.com/7f024c2e906bd0f298cbf154a4dbf7b76f6f9f94e7b1343f8045d516cc5e5e86-image.png)


```
from functools import lru_cache

class Solution:

    @lru_cache(typed=False)
    def isValid(self, total_str, pos1, s2, pos2, s3, pos3) -> bool:
        if pos2 == len(s2):
            return s3[pos3:] == total_str[pos1:]

        i, j = pos1, pos2
        while i < len(total_str) and j < len(s2):
            if total_str[i] != s2[j]:
                break

            if self.isValid(total_str, i + 1, s3, pos3, s2, j + 1):
                return True
            i, j = i+1, j+1

        return False


    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s3) != len(s1) + len(s2):
            return False
        return self.isValid(s3, 0, s1, 0, s2, 0) or self.isValid(s3, 0, s2, 0, s1, 0)
```
