```
from bisect import bisect


class WordDistance:

    def __init__(self, words: List[str]):
        self.d={w:[] for w in words}
        for i in range(len(words)):
            self.d[words[i]].append(i)

    def shortest(self, word1: str, word2: str) -> int:
        ans=1<<30
        if word1==word2:
            i1=d[word1]
            return min(i1[j+1]-i1[j] for j in range(len(i1)-1))
        i1,i2=self.d[word1],self.d[word2]
        for i in i1:
            j=bisect(i2,i)
            l,r=j+1,j-1
            for k in (j,l,r):
                if 0<=k<len(i2):
                    ans=min(ans,abs(i-i2[k]))
        return ans
```
