```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        num1 = len(s)
        if s == "":
            return("")
        aa = 1
        for i in range(num1 - 1,-1,-1):
            for j in range(aa):
                str1 = s[j:j+i+1]
                str2 = str1[::-1]
                if str1 == str2:
                    return(str1)
            aa = aa + 1
```

