倒序匹配，找出第一个不为空格的字符，逐一判断，直到下一个空格字符。
```
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        lens = len(s)-1
        res=0
        while lens>=0:
            if s[lens]==' ':
                if res==0:
                    lens-=1
                    continue
                else:
                    return res
            else:
                res+=1
                lens-=1
        return res
```
