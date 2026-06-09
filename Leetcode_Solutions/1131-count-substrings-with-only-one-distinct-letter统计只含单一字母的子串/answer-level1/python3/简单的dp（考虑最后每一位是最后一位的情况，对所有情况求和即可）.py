```
class Solution:
    def countLetters(self, S: str) -> int:
        if S=='':
            return 0
        dp=[1]*S.__len__()
        
        for i in range(1,S.__len__()):
            if S[i]==S[i-1]:
                dp[i]=dp[i-1]+1
        return sum(dp)
```
