用正则匹配一步求解
给定s和p，用re.findall(p,s)找出所有满足条件的字符串

```
import re


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        res = re.findall(p, s)
        if len(res)>0 and res[0]==s:
            return True
        else:
            return False
```
