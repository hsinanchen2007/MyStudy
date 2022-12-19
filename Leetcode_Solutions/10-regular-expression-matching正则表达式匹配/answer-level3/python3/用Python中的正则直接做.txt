用的re模块,好像有点赖皮..
```
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        import re
        if re.findall(p,s) and re.findall(p,s)[0]==s:
            return True
        else:
            return False
```
