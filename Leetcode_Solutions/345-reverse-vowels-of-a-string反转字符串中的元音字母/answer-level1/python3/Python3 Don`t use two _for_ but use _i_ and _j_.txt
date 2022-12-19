### 解题思路
I used two for but I failed. 

### 代码

```python3
class Solution:
    def reverseVowels(self, s: str) -> str:
        yuanyin="aeiouAEIOU"
        s=list(s)
        i=0
        j=len(s)-1
        while i<j:
            if s[i] not in yuanyin:
                i+=1
            if s[j] not in yuanyin:
                j-=1
            if s[i] in yuanyin and s[j] in yuanyin:
                s[i],s[j]=s[j],s[i]
                i+=1
                j-=1
        return "".join(s)
```