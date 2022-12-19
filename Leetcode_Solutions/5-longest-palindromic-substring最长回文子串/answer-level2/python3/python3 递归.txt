### 解题思路
此处撰写解题思路
在递归函数里面确定：
1、进入递归函数对参数的值范围进行限制
2、满足条件后递归函数进行参数的递归，同时对有范围规定的值进行范围分类
3、对特殊情况单独处理

### 代码

```python3
def guihua(a, b, s, substring):
    if(0>a or b>=len(s)):return substring
    if(s[a] == s[b]):
        substr = s[a] + substring
        substr = substr + s[b]
        if(0<a and b<len(s)):
            a = a - 1
            b = b + 1
            ssss = guihua(a, b, s, substr)
            return ssss
        elif(a==0 or b==len(s)):return substr
        else:return substring
    else:
        if len(s)==2:return s[1]
        return(substring)

class Solution:
    def __init__(self):
        self.count = 0
        self.lenstring = 0
        self.string = ""

    def longestPalindrome(self, s: str) -> str:
        if(len(s)==1): return s
        for i in range(1,len(s)-1):
            if(i>len(s)-self.lenstring/2):break
            a = i-1
            b = i+1
            count = 0
            substring = s[i]
            substring= guihua(a, b, s, substring)
            if(len(substring)>self.lenstring):
                self.lenstring = len(substring)
                self.string = substring
        for i in range(int(self.lenstring/2), len(s) - 1):
            if(i>len(s)-self.lenstring/2):break
            a = i
            b = i + 1
            substring = ""
            substring = guihua(a, b, s, substring)
            if(len(substring)>self.lenstring):
                self.lenstring = len(substring)
                self.string = substring
        return(self.string)
           


           


```