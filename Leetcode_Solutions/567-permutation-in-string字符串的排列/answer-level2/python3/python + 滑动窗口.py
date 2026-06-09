```python
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s2) < len(s1): return False
        dic = collections.Counter(s1)
        key = [x for x in dic.keys()]
        i = 0
        for j, st in enumerate(s2):
            if st in key:
                if dic[st] != 0:
                    dic[st] -= 1
                    if dic[st] == 0: del dic[st]
                else:
                    while i < j and dic[st] == 0:
                        if s2[i] in key: dic[s2[i]] += 1
                        i += 1
                    del dic[st]
            else:
                while i < j:
                    if s2[i] in key: dic[s2[i]] += 1
                    i += 1
            
            if len(dic) == 0: return True
        return False
```