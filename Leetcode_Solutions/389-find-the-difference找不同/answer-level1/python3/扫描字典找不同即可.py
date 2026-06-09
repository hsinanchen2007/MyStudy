```
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        from collections import Counter
        
        if s=="":
            return t
        
        s_dic=Counter(s)
        t_dic=Counter(t)
        
        for key in t_dic:
            if key not in s_dic:
                return key
            else:
                if t_dic[key]!=s_dic[key]:
                    return key
```