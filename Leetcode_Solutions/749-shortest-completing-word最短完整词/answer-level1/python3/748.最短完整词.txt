```
class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        li=[i.lower() for i in licensePlate if i.isalpha()]
        c=collections.Counter(li)
        ans=''
        length=1001
        for word in words:
            w=collections.Counter(word)
            if all([c[i]<=w[i] for i in c]):
                if len(word)<length:
                    length=len(word)
                    ans=word

        return ans
```
