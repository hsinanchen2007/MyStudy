
相当于26进制:

```
class Solution:
    def titleToNumber(self, s: str) -> int:
        # return ord("A")  # A = 65
        return sum( [(ord(s[i])-64) * 26 ** (len(s)-1-i) for i in range(len(s))]) 

```

