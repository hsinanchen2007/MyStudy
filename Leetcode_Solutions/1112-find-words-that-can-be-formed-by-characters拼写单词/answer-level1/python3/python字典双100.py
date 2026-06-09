```
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        dic={}
        for i in chars:
            if dic.get(i):
                dic[i]+=1
            else:
                dic[i]=1
        
        res=0
        for word in words:
            a=0
            for j in word:
                if dic.get(j) and word.count(j)<=dic[j]:
                    a+=1
                else:
                    break
            if a==len(word):
                res+=a
        
        return res
```
