递归的算法，但是时间复杂度比较高，只通过了39个测试用例。

```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) <= 1:
            return s
        else:
            if s[0] == s[-1]:
                if self.isPalindrome(s[1:-1]):
                    return s
                else: 
                    left = self.longestPalindrome(s[0:-1]) 
                    right = self.longestPalindrome(s[1::]) 
                    if len(left) >= len(right):
                        return left
                    else:
                        return right
            else:
                left = self.longestPalindrome(s[0:-1])
                right = self.longestPalindrome(s[1::])
                if len(left) >= len(right):
                    return left
                else:
                    return right
    def isPalindrome(self, s: str) -> bool:
        if len(s) <= 1:
            return True
        else:
            return s[0] == s[-1] and self.isPalindrome(s[1:-1])
```
