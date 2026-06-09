```
class Solution:
    def reverseVowels(self, s: str) -> str:
        alpha = list('aeiouAEIOU')
        n = len(s)
        s = list(s)
        i = 0
        j = n-1
        while i<j:
            while i<j and s[i] not in alpha:
                i += 1
            while i<j and s[j] not in alpha:
                j -= 1
            s[i],s[j]=s[j],s[i]
            i+=1
            j-=1
        return ''.join(s)
```
