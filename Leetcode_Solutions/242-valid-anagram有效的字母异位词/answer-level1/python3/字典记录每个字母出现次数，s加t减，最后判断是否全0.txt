
```
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dic={}
        for letter in s:
            if letter in dic:
                dic[letter]+=1
            else:
                dic[letter]=1
        for letter in t:
            if letter in dic:
                if dic[letter]<=0:
                    return False
                else:
                    dic[letter]-=1
            else:
                return False
        a=list(dic.values())
        for i in a:
            if i!=0:
                return False
        return True
```
