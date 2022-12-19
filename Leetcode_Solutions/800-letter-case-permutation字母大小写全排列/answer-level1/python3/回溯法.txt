```
class Solution:
    def letterCasePermutation(self, S: str) -> list:
        ans = []
        
        def backtrack(S, p):
            ans.append(S)
            for k in range(p, len(S)):
                if 'a' <= S[k] <= 'z':
                    backtrack(S[:k]+S[k].upper()+S[k+1:], k+1)
                elif 'A' <= S[k] <= 'Z':
                    backtrack(S[:k]+S[k].lower()+S[k+1:], k+1)
            return
        
        backtrack(S, 0)
        return ans
```
