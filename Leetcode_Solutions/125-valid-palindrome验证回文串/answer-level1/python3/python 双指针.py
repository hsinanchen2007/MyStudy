双指针快 时间o(n)

```
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        left = 0
        right = len(s) - 1
        while left < right:
            while left<right and not s[left].isalnum():
                left += 1
            while left<right and not s[right].isalnum():
                right -= 1
            if s[left] == s[right]:
                right -= 1
                left += 1
            else:
                return False
        return True
```
