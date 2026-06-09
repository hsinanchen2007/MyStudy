```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        length = len(s)
        if length == 0:
            return ""
        matrix = [[False] * length for i in range(length)]
        start, end = 0, 0
        for i in range(length):
            matrix[i][i] = True
            if i != length - 1:
                matrix[i][i+1] = s[i] == s[i+1]
                if matrix[i][i+1] and (end - start) < 1:
                    start, end = i, i + 1
        i = length - 3
        while i >= 0:
            j = i + 2
            while j < length:
                matrix[i][j] = matrix[i+1][j-1] and s[i] == s[j]
                if matrix[i][j] and (end - start) < (j - i):
                    start = i
                    end = j
                j += 1
            i -= 1
        return s[start:end+1]
```
