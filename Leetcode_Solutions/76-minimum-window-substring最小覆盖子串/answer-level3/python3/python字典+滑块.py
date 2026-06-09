
```python3
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t:return ""
        left,right=0,0
        n=len(s)
        dic={}
        for a in t:
            if a in dic:dic[a]+=1
            else:
                dic[a]=1
        m=""
        lr=0
        while right<=n-1:
            if s[right] in dic:
                dic[s[right]]-=1
                if all(_<=0 for _ in dic.values()):
                    while s[left] not in dic or dic[s[left]]<0:
                        if s[left] not in dic:
                            left+=1
                        elif s[left] in dic and dic[s[left]]+1<=0:
                            dic[s[left]]+=1
                            left+=1
                    if lr==0 or right-left<lr:
                        m=s[left:right+1]
                        lr=right-left
            right+=1
        return m
```