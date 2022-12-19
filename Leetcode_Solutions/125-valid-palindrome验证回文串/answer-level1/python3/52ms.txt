```
class Solution:
    def isPalindrome(self, s: str) -> bool:
        n1 = len(s)
        str1 = ""
        for i in range(n1):
            if s[i].isdigit() or s[i].isalpha():
                str1 += s[i].lower()
        str2 = str1[::-1]
        if str1 == str2:
            return(True)
        else:
            return(False)
```
