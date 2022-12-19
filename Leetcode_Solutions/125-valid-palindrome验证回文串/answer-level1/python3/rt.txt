```
class Solution:
    def isPalindrome(self, s: str) -> bool:
        if not s: return True
        temps = [i.lower()  for i in s if i.isalnum()]
        return temps == temps[::-1]
```
