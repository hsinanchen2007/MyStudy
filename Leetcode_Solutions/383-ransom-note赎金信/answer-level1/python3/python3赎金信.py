使用哈希表字典解决
```
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mdic = dict()
        for i in magazine:
            if mdic.get(i)!=None:
                mdic[i]+=1
            else:
                mdic[i]=1
        for j in ransomNote:
            if mdic.get(j):
                mdic[j]-=1
            else:
                return False
        return True
```
