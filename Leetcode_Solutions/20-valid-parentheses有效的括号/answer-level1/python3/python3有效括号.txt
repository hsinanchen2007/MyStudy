class Solution:
    def isValid(self, s: str) -> bool:
        if len(s)%2 != 0:
            return False
        pipei_dict,stack = {'}':'{',']':'[',')':'('},[]
        for i in range(len(s)):
            if s[i] == '[' or s[i] == '{' or s[i] == '(':
                stack.append(s[i])
            elif i > 0 and stack[-1] == pipei_dict[s[i]]:
                stack.pop()
            else:
                return False
        if len(stack) == 0:
            return True
        return False