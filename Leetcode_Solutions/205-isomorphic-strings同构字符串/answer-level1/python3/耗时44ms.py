```
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        zidian1 = {}
        zidian2 = {}
        n1 = len(s)
        for i in range(n1):
            if s[i] not in zidian1.keys():
                list1 = zidian1.values()
                if t[i] in list1:
                    return(False)
                zidian1[s[i]] = t[i]
            else:
                if zidian1[s[i]] != t[i]:
                    return(False)
        return(True)
```
