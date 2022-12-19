### 解题思路
用数学归纳法找了找规律，感觉都没有用程序解决问题，惭愧。
### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        regular = 2 * (numRows - 1)
        string = ''
        if numRows == 1:
            return s
        for line in range(numRows):
            j = 0
            while(1):
                if line == 0 or line == numRows - 1:
                    an = line + j * regular
                else:
                    if j % 2 == 0:
                        an = line + int((j + 1) / 2) * regular
                    else:
                        an = -1 * line + int((j + 1) / 2) * regular
                j += 1
                if an >= len(s):
                    break
                string += s[an]
        return string
```