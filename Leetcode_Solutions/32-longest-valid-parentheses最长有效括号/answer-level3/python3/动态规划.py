class Solution:
    def longestValidParentheses(self, s: str) -> int:
        # L[i] 保存右末尾在s[i]的最长有效子串的长度
        L = [0] * len(s)
        if len(s) < 2:
            return 0
        if s[0] == '(' and s[1] == ')':
            L[1] = 2
        
        maxl = L[1]
        
        for i in range(2, len(s)):
            if s[i] == ')' and s[i-1] == '(':
                L[i] = L[i-2] + 2
            elif s[i] == ')' and s[i-1] == ')':
                if i-1-L[i-1] >= 0 and s[i-1-L[i-1]] == '(':
                    L[i] = L[i-1] + L[i-2-L[i-1]] + 2
        
            if L[i] > maxl:
                maxl = L[i]
        # print(L)        
        return maxl