### 解题思路
此处撰写解题思路
第一步反转每个单词，第二步将整个字符串反转
### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        i = 0
        p=''
        while i<len(s) :
            
            while i<len(s) and s[i]==' ':
                i+=1
            if i==len(s):
                break
            j=i
            while j<len(s) and s[j]!=' ':
                j+=1
            if i<j:
               if p=='':
                  l = s[i:j]
                  p=p+l[::-1]
               else:
                  l = s[i:j]
                  p = p+' ' +l[::-1]
            i=j
            i+=1
        s = p[::-1]
        return s
```