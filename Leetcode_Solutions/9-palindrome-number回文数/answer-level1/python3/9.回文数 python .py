```
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        else:
            x = str(x)
            if x[::-1] == x[::1]:
                return True
            else:
                return False


a = Solution()
a.isPalindrome(121)
```
解题思路：感觉还是我最简洁~~如果是负数，直接就false，如果是正数，数字正反必相等。