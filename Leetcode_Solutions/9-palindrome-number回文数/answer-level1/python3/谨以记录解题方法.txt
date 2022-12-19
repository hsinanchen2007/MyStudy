```
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x >= 0 :
            s = str(x)
            s1 = ""
            for i in s:
                s1 = i + s1
            if s1 == s:
                return True
            else:
                return False
        else:
            return False
```
直接暴力使用转字符串的方法解题。
