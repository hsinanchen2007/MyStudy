### 解题思路
画出numRows=5的Z型排列，结合题干中numRows=3和numRows=4的情况，列出每个字母的下标，可看出规律
将字符串以2*(numRows-1)的长度分组，逐行、逐组根据下标规律获取字符

### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        chunk_len = 2*(numRows-1)
        chunks = [s[i:i+chunk_len] for i in range(0, len(s), chunk_len)]
        result = ''
        for i in range(numRows):
            if i == 0 or i == numRows-1:
                for chunk in chunks:
                    result += chunk[i] if i<len(chunk) else ''
            else:
                for chunk in chunks:
                    result += chunk[i] if i<len(chunk) else ''
                    result += chunk[chunk_len-i]  if chunk_len-i<len(chunk) else ''
        return result
```