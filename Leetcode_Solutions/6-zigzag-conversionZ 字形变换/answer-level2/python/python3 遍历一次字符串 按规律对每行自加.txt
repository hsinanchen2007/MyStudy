### 解题思路
python3按照Z字形规律，遍历一遍s，对相应的行字符串进行自加。最后将所有行连接起来。哈哈，果然还是python写字符串的题简单方便。

### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows<=1: return s

        s_rows = [''] * numRows
        for i in range(len(s)):
            m = i%(2*numRows-2)
            s_rows[m if m<numRows else 2*numRows-2-m] += s[i]
        # print(s_rows)
        return ''.join(s_rows)
```