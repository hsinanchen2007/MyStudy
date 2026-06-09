class Solution:
    def longestPrefix(self, s: str) -> str:
       
        l = len(s)
        rs = ""
        for i in range(len(s)):
            if s[:i] == s[l-i:]:
                rs = s[:i]
        return rs
