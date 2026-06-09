### 解题思路
去除多余空格，再判断串首字符是否符合要求，再依次遍历。

### 代码

```python3
class Solution:
    def strToInt(self, str: str) -> int:
        s = str.strip()
        if not s or s[0] not in '+-0123456789':
            return 0
        res = s[0]
        i = 1
        while i < len(s):
            if s[i] in '0123456789':
                res += s[i]
                i += 1
            else:
                break
        if res == '+' or res == '-':
            return 0
        if int(res) > 2**31 - 1:
            return 2**31 - 1
        if int(res) < -2**31:
            return -2**31
        return int(res)
            
```