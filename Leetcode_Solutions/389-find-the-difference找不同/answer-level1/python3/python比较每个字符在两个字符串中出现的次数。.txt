被添加的那个字符在两个字符串中出现的次数应该相差1：



```
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        for i in t:
            if t.count(i)-s.count(i)==1:
                return i
```
