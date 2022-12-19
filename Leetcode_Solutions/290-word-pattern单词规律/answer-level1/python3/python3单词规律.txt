```
class Solution:
    def wordPattern(self, pattern: str, str1: str) -> bool:
        len1=len(pattern)
        strlist = str1.split(' ')
        len2=len(strlist)
        if len1 != len2:
            return False
        dic={}
        for i in range(len1):
            if dic.get(pattern[i])!=None:
                if strlist[i]!=dic[pattern[i]]:
                    return False
                else:
                    continue
            elif strlist[i] in dic.values():
                return False  
            else:
                dic[pattern[i]]=strlist[i]
        return True
```
