在字符串错位拼接上遇到了麻烦，只能用笨方法for循环拼接
```
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows < 1:
            raise ValueError
        if numRows == 1:
            return s
        if not len(s):
            return ''

        m = numRows + numRows - 2
        result = ''
        result += s[::m]

        if numRows >= 2:
            for i in range(1, numRows - 1):
                a1 = s[i::m]
                a2 = s[m-i::m]

                for j in range(len(a2)):
                    result += a1[j] + a2[j]

                result += a1[-1] if len(a1) > len(a2) else ''

        result += s[numRows-1::m]

        return result
```
