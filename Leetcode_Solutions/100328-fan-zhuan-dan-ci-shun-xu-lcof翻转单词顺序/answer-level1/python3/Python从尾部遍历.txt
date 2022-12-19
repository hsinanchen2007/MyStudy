### 解题思路
先去除首尾空格，然后从尾部遍历，遇到空格则找到一个单词。注意对首位单词的处理（前面没有空格了）

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()
        res = ''
        tmp = ''
        n = len(s)
        for i in range(n-1,-1,-1):
            if s[i] != ' ':
                tmp += s[i]
            if s[i] == ' ' and s[i + 1] != ' ':
                    res += tmp[::-1]
                    res += ' '
                    tmp = ''
            if i == 0:
                res += tmp[::-1]
        return res
```