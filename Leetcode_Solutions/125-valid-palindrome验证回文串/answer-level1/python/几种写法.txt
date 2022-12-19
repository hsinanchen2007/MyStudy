### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:

        # s = (''.join(list(filter(str.isalnum, s.lower()))))
        s = [*filter(str.isalnum, s.lower())]
        # return s == s[::-1]

        l, r = 0, len(s)-1
        while l < r:
            if s[l] != s[r]: 
                return False
            l += 1
            r -= 1
        return True

```