利用python的特性进行解决

```
class Solution:
    def isPalindrome(self, s: str) -> bool:
        # if not s:
        #     return True
        s = list(filter(str.isalnum, s.lower()))
        # print(s)
        if s == s[::-1]:
            return True
        return False

```
