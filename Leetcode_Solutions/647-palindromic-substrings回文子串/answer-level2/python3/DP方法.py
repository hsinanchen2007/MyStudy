```
class Solution:
    def countSubstrings(self, s: str) -> int:
        L=len(s)
        if L==0:return 0
        if L==1:return 1
        dp=[[False for _ in range(L)]for _ in range(L)]
        res=0
        for r in range(L):
            for l in range(r+1):
                if r==l:
                    dp[l][r]=True
                    res+=1  
                elif s[l]==s[r] and(r-l<=2 or dp[l+1][r-1]):
                    dp[l][r]=True 
                    res+=1
        return res
```
