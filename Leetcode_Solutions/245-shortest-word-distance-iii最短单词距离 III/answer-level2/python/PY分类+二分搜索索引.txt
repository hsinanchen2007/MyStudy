可以线性搜索，但是不容易AC（这个代码一次AC了）
```
from bisect import bisect


class Solution:
    def shortestWordDistance(self, words: List[str], word1: str, word2: str) -> int:
        n=len(words)
        ans=n
        if word1==word2:
            prev=-n
            for i in range(n):
                w=words[i]
                if w==word1:
                    ans=min(ans,i-prev)
                    prev=i
            return ans
        i1,i2=[],[]
        for i in range(n):
            w=words[i]
            if w==word1:
                i1.append(i)
            if w==word2:
                i2.append(i)
        for i in i1:
            j=bisect(i2,i)
            l,r=j+1,j-1
            for k in (j,l,r):
                if 0<=k<len(i2):
                    ans=min(ans,abs(i-i2[k]))
        return ans
```
