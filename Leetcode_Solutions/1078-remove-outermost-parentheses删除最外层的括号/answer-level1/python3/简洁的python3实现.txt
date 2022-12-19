class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        s = ""
        stack = []
        for i in S:
            if i == "(":
                stack.append(i)
                if len(stack) != 1:
                    s += i
            else:
                stack.pop()
                if len(stack) != 0:
                    s += i
        return s