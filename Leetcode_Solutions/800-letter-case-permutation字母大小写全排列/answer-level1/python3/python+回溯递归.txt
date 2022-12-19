```
class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        if not S:
            return ['']
        S = S.lower()
        ans = [S]
        def helper(i,S):
            if i == len(S):
                return
            if ans[-1] == S.upper():
                return ans
            if S[i].isalpha():
                l = S[:i] + S[i].upper() + S[i+1:]
                ans.append(l)
                helper(i+1,S)
                helper(i+1,l)
            else:
                i += 1
                helper(i,S)
        helper(0,S)
        return ans
```
