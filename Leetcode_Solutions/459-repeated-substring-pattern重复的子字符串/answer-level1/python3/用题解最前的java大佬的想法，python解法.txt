```
class Solution:
    def repeatedSubstringPattern(self, s):
        s1 = s+s
        return (s in s1[1:len(s1)-1])
    #s = n个相同的字符串相加
    #假设 n = 'ab',s = 'abab'=n+n
    #所以 s1 = s+s = 'abab'+'abab' = n+n+n+n
    #那么破坏第一个和最后一个n,则 s1 = '坏'+n+n+'坏'
    #所以s必然在s1中，如果不在则说明s不是由相同的n构成的，即不符合条件！！！
```
