class Solution:
    def isPalindrome(self, x: int) -> bool:
        x = str(x) 
        x_reverse = str(x)[::-1]
        return x == x_reverse