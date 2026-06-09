### 解题思路

用好字典和循环，累加就完事了。

### 代码

```
class Solution:
    def romanToInt(self, s: str) -> int:
        luoma_map = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        special_map = {'IV':4,'IX':9,'XL':40,'XC':90,'CD':400,'CM':900}
        num = 0
        i = 0
        while i < len(s) :
            if i<len(s)-1 and s[i:i+2] in ['IV','IX','XL','XC','CD','CM']:# special_map.key()
                num+=special_map[s[i:i+2]]
                i+=2
            else:
                num +=luoma_map[s[i]]
                i+=1
        
        return num

```
