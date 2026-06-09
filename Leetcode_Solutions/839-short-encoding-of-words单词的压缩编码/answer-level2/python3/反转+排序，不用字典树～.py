```
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words=sorted([word[::-1] for word in words])#会按照字典序排序
        res=len(words[0])
        count=1
        for i in range(1,len(words)):
            if words[i].startswith(words[i-1]):
                res+=len(words[i])-len(words[i-1])
            else:
                res+=len(words[i])
                count+=1
        return res+count
```
