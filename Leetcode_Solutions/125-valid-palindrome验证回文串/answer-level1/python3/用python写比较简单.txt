class Solution:
    def isPalindrome(self, s: str) -> bool:
        if s == "":
            return True
        s = s.lower()
        s = s.replace(" ", "" )
        s = "".join(e for e in s if e.isalnum())
        if s[:] == s[-1::-1]: 
            return True
        else:
            return False
            