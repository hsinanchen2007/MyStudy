```
class Solution:
    def reverseWords(self, s: str) -> str:
        # 加一个空格方便后面else反转
        s+=" "
        res,tmp="",""
        for i in range(len(s)):
            if not s[i].isspace():
                tmp+=s[i]
            else:
                tmp=tmp[::-1]
                res+=tmp+" "
                tmp=""
        return res[:-1]
        
```
