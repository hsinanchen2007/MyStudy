- 详细程序终止情况
- p == '' and s == ''  true
- p == '' and s!= '' false
- s == '' and p!='': len(p)<2 or p[1] != '*' return false
-                   else: return ismatch(s,p[2:])
- 注意测试 s='ab' p='.*'   s=a p='.*'   s=a p='c*ab*'等情况
```
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        #specially s=''&p='.*'    s='a'&p='b*ac*' s='ab'&p='.*'  
        if p =='':
            return s == ''
        if s == '':
            if len(p) < 2 or p[1] != '*': #单独处理 s='' p='.*ccc'这种情况
                return False
            else:
                return self.isMatch(s,p[2:])
        
        firstMatch = (s != '') and (p[0] == s[0]) or (p[0] == '.')
        if len(p) >= 2 and p[1] == '*':
            #"a*" 用0次(a* = '') 1次(a* = 
            return self.isMatch(s,p[2:]) or (firstMatch and self.isMatch(s[1:],p))
        else:
            return firstMatch and self.isMatch(s[1:],p[1:])
```
