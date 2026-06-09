class Solution:
    def isPalindrome(self, s: str) -> bool:
        return ("".join(filter(str.isalnum, s)).lower()[::-1]) == ("".join(filter(str.isalnum, s)).lower())