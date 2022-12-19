```
class Solution:
    def generatePossibleNextMoves(self, s: str) -> List[str]:
        ans=[]
        for i in range(len(s)-1):
            if s[i]==s[i+1]=='+':
                ans.append(s[:i]+'--'+s[i+2:])
        return ans
        
```
