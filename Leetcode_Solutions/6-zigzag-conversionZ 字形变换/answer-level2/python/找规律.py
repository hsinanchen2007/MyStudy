### 解题思路
就是找规律，对着numRows=4的看就是了

### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if len(s) <= numRows or numRows == 1:
            return s
        result = ""
        for i in range(numRows):
            j = 0
            index = i
            while index < len(s):
                result += s[index]
                j += 1
                if i == 0 or i == numRows-1:
                    index += 2 + 2 * (numRows - 2)
                else:
                    if j % 2 == 1:
                        index += 2 + 2 * (numRows - i - 2)
                    else:
                        index += 2 + 2 * (i - 1)
        return result
```