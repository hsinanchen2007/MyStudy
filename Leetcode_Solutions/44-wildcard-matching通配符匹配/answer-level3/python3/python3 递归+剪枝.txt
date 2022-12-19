无论是正则式匹配还会通配式匹配，核心在于处理好字符'*'.
pattern式中的'*'匹配字符串的字符，进行移动时存在三种情况，分别是：
（1）匹配任意长的字符，s[1:],p
（2）匹配空字符时移除'*',s,p[1:]
（3）同时移动 s[1:],p[1:]

第一种：直接递归，遍历所有情况
```
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if not p:
            return True if not s else False
        
        if s == '':# 处理特殊情况
            return True if p.replace('*','')== '' else False
        
        if p[0] == '*':
            return self.isMatch(s[1:],p[1:]) or self.isMatch(s,p[1:]) or self.isMatch(s[1:],p)
        elif p[0] == '?':
            return self.isMatch(s[1:],p[1:])
        else:
            return self.isMatch(s[1:],p[1:]) if s[0] == p[0] else False
```
但是遇到函数调用很深的情况，就会超时。比如这个测试样例。
```
s= "babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab"
p ="***bba**a*bbba**aab**b"
```

第二种方法：递归+剪枝，或称为带记忆的递归。就是在递归的过程中，记录已经处理过的位置，避免重复计算。
```
class Solution:
    def helper(self,s,p,i,j,lookup):
        # print(s,p,i,j,lookup)
        if self.flag == True or (i,j) in lookup:
            return
        if not p:
            if not s:
                self.flag = True
            return

        if s == '':  # 处理特殊情况
            if p.replace('*', '') == '':
                self.flag = True
            return

        if p[0] == '*':
            self.helper(s[1:], p[1:],i+1,j+1,lookup)
            self.helper(s, p[1:],i,j+1,lookup)
            self.helper(s[1:], p,i+1,j,lookup)

        elif p[0] == '?':
            self.helper(s[1:], p[1:],i+1,j+1,lookup)
        else:
            if s[0]==p[0]:
                self.helper(s[1:], p[1:],i+1,j+1,lookup)
        if not self.flag:
            lookup.add((i,j))

    def isMatch(self, s, p):
        self.flag = False
        lookup = set()
        self.helper(s,p,0,0,lookup)
        return self.flag
```

最后时间是1492 ms。超过了20%。比我想象得要慢。。。还可以继续优化。