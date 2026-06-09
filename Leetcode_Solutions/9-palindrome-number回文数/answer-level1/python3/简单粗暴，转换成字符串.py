class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        else:
            if str(x) == str(x)[::-1]:
                return True
            else:
                return False
思路非常简单