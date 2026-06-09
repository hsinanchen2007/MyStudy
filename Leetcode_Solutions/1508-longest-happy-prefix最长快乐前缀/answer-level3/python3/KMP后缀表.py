# 思路
KMP后缀表的定义即是当前位置的前缀后缀匹配长度，建里起后缀表即可。
tips:在字符串后添加停止符号可以使代码更简洁
时间复杂度：$O(n)$
空间复杂度：$O(n)$
#代码
```python
class Solution:
    def longestPrefix(self, s: str) -> str:
        if len(s)<2:
            return ""
        if len(s)==2:
            if s[0]==s[1]:
                return s[0]
            else:
                return ""
        s+='$'
        T=[0]*len(s)
        pos=2
        cnd=0
        T[0]=-1
        T[1]=0
        while pos<len(s):
            if s[pos-1]==s[cnd]:
                cnd+=1
                T[pos]=cnd
                pos+=1
            elif cnd>0:
                cnd=T[cnd]
                
            else:
                T[pos]=0
                pos+=1
        return s[:T[-1]]
        
```
