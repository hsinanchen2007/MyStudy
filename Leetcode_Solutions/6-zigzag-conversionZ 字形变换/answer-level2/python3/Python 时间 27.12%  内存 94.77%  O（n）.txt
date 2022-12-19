判断下标即可
```
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows <= 1:
            return s
        j, l = 0, numRows * 2 - 2

        result = ""
        for i in range(numRows):
            j = 0
            if i == 0 or i == numRows - 1:
                while i + l * j < len(s):
                    result += s[i + l * j]
                    j += 1
            else:
                while i + l * j < len(s):
                    result += s[i + l * j]
                    if l * j + l - i < len(s):
                        result += s[l * j + l - i]
                    j += 1
        return result
```