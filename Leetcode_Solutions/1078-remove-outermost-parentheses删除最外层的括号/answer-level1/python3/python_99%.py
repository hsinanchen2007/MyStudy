1. class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        stack = []
        res = []
        for i in range(len(S)):
            if S[i] == '(':
                stack.append(S[i])
            if len(stack)>1:
                res.append(S[i])
            if S[i] == ')':
                stack.pop()
            
        return "".join(res)