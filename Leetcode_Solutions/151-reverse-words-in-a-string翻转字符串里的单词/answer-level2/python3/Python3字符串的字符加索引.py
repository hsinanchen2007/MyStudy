### 解题思路
Python3字符串的字符加索引

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        res = ''
        s += " "
        idx = 0
        flag = False
        for j , i in enumerate(s):
            if not flag and i != " ":
                idx = j
                flag = True
            elif flag and i == ' ':
                flag = False
                res = " " +  s[idx:j] + res
        return res[1:]
```