class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x % 10 == 0 and x != 0):
            return False

        n = len(str(x))

        for i in range(n//2):
            if x // 10**(i) % 10 != x // 10**(n-i-1) % 10:
                return False
        return True