```
class Solution:
    
    def romanToInt(self, s: str) -> int:
        ro={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000,'A':0}
        s=s+'A'
        all=0
        for le in range(len(s)-1):
            if ro[s[le]]>=ro[s[le+1]]:
                all+=ro[s[le]]
            else:
                all-=ro[s[le]]
        return all
        
sol=Solution()
sol.romanToInt('III')
```
解题思路：由于遍历每个字符都会需要与后一个做比较，所以正常情况下我们无法计算到最后的一个字符，如果给到的是单个字符如‘I'同意无法计算。
这个方法是在给到的英文字符后面补一个数‘A’，在字典中添加对应的value为0，就可以实现代码的正常运行。
