```
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        stack = ['(']
        l = [-1]
        for i in range(1,len(S)):
            if S[i] == '(':
                stack.append('(')
            else:
                stack.pop()
            if not stack:
                l.append(i)
        ans = ''
        for i in range(len(l)-1):
            ans += S[l[i]+2:l[i+1]]
        return ans
```
