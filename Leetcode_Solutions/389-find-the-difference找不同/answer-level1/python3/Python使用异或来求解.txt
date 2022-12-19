其实用dict也可以做，不过我就是练习一下位运算
```
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        res = 0
        for i in s:
            res ^= ord(i)
        for j in t:
            res ^= ord(j)
        return chr(res)
```
