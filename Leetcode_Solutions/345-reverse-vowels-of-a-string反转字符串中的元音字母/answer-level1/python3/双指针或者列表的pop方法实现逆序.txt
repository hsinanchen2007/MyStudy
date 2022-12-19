方法一：ls存储单词中的所有元音字母，遍历当前字符串，若为辅音字母直接添加，若为元音字母，pop方法取出最后一位元音字母，添加至目标列表
```
class Solution:
    def reverseVowels(self, s: str) -> str:
        x={'a','e','i','o','u','A','E','I','O','U'}
        res=[]
        ls=[i for i in s if i in x]        
        for k in s:
            if k not in x:
                res.append(k)
            else:
                res.append(ls.pop())       
        return ''.join(res)
```
方法二：双指针，左指针遇到一个元音字母，右指针就从后往前遍历，交换第一个元音字母
```
class Solution:
    def reverseVowels(self, s: str) -> str:
        x={'a','e','i','o','u','A','E','I','O','U'}
        res=[]
        j=len(s)-1
        for i,k in enumerate(s):
            if k in x:                      
                while s[j] not in x:
                    j-=1
                res.append(s[j])
                j-=1
            else:
                res.append(k)
        return ''.join(res)
```

