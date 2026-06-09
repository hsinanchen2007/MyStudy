```
class Solution:
    def reverseWords(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        def reverse(s, l, r):
            while(l<r):
                s[l], s[r] = s[r], s[l]
                l += 1
                r -= 1
        reverse(s, 0, len(s)-1)
        l = 0
        for i in range(len(s)):
            if s[i] != ' ':
                continue
            reverse(s, l, i-1)  
            l = i + 1
        reverse(s, l, len(s)-1)
```
