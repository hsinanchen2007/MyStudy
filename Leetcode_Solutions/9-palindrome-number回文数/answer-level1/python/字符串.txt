class Solution:
    def isPalindrome(self, x: int) -> bool:
        x1=list(str(x))
        x1.reverse()
        x=list(str(x))
        return x1==x