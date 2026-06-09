class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        return -1 if needle not in haystack else haystack.index(needle)
