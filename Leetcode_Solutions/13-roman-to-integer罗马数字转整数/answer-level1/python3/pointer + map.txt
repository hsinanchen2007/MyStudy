```
class Solution:
    def romanToInt(self, s: str) -> int:
        map = {'M':1000,'CM':900,'D':500,'CD':400,'C':100,'XC':90,'L':50,'XL':40,
        'X':10,'IX':9,'V':5,'IV':4,'I':1}
        pointer, result = 0,0
        while pointer < len(s):
            if s[pointer:pointer+2] in map:
                result += map[s[pointer:pointer+2]]
                pointer += 2
            else:
                result += map[s[pointer]]
                pointer += 1
        return result


```
