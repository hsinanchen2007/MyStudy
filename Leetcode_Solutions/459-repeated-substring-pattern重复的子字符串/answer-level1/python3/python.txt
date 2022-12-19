class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n = len(s)
        for i in range(1, n // 2 + 1):
            if n % i != 0:
                continue
            if s[0:i] * (n // i) == s:
                return True
        return False