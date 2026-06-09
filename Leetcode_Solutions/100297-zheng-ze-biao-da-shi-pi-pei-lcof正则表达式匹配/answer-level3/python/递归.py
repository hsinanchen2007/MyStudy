### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if not p:return not s
        if len(p)>1 and p[1]=='*':
            return self.isMatch(s,p[2:]) or (s!='' and (s[0]==p[0] or p[0]=='.') and self.isMatch(s[1:],p)) or (s!='' and (s[0]==p[0] and p[0]=='.') and self.isMatch(s[1:],p[2:]))
        if s and (s[0]==p[0] or p[0]=='.'):return self.isMatch(s[1:],p[1:])
        return False
```