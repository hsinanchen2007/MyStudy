```
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        balance = 0
        sub = []
        last = 0
        for i,s in enumerate(S):
            if s =='(':
                balance += 1
            elif s == ')':
                balance -= 1
            if balance == 0:
                sub.append(S[last:i+1])
                last = i + 1
        res = ''
        for s in sub:
            res += s[1:-1]
        return res
```
