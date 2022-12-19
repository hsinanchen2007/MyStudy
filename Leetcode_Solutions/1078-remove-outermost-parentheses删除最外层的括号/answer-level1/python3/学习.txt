1. 
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        n = 0
        str_b = ''
        for c in S:
            if c == '(':
                n += 1
                if n > 1:
                    str_b += c
            else:
                if n > 1:
                    str_b += c
                n -= 1
        return str_b