```
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        #利用哈希表
        dic1={}
        dic2={}
        lenth=len(s)
        for i in range(lenth):
            if s[i] in dic1:
                if dic1[s[i]]!=t[i]:
                    return False
            else:
                dic1[s[i]]=t[i]
            if t[i] in dic2:
                if dic2[t[i]]!=s[i]:
                    return False
            else:
                dic2[t[i]]=s[i]
        return True
```
