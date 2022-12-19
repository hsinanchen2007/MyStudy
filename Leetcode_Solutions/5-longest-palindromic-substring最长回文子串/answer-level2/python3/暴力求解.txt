### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        longest = ''
        for i in range(0, len(s)-1):
            if s[i] == s[i+1]:
                p = self._getPalindrom(s, i, i+1)
                if len(p) > len(longest):
                    longest = p
                    
            if i > 0 and s[i-1] == s[i+1]:
                p = self._getPalindrom(s, i-1, i+1)
                if len(p) > len(longest):
                    longest = p
        if len(longest) == 0 and len(s) > 0:
            return s[0] 
        return longest  

    def _getPalindrom(self, s: str, l, r)->str:
        r += 1
        for l in range(l-1, -1, -1):
            if r >= len(s) or s[l] != s[r]:
                return s[l+1:r]
            r += 1
        return s[l:r]
                

```