class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        m=len(s)
        s1=s[n:m]+s[0:n]
        return s1