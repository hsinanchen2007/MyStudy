
切割单词，直接存字典统计

```python
class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        aa, bb = collections.Counter(A.split(" ")), collections.Counter(B.split(" "))
        w = set(list(aa.keys()) + list(bb.keys()))
        #print(w)
        res = []
        for word in w:
            if word in aa and word not in bb and aa[word] == 1:
                res.append(word)
            if word in bb and word not in aa and bb[word] == 1:
                res.append(word)    
        #print(res)        
        return res
```