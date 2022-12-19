将所有可能结果放到一个字典中，然后遍历一遍字符串即可~
```
class Solution:
    def romanToInt(self, s: str) -> int:
        dic={
            'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000,
            'XL':40,'XC':90,'CD':400,'CM':900,'IV':4,'IX':9
        }
        _len=len(s)
        i=0
        num=0
        while i<_len:
            if i+1<_len and s[i:i+2] in dic:
                num+=dic[s[i:i+2]]
                i+=2
            else:
                num+=dic[s[i]]
                i+=1
        return num

```
