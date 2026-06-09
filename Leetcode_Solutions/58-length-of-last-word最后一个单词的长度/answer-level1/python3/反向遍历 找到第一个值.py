### 解题思路
反向遍历字符串, 忽略所有还未遇其他字符串的空白, 然后获得单词长度,返回值

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if (s == "" or s == " "):
            return 0
        length = 0
        for i in range(len(s) - 1, -1, -1):
            if (s[i] == " "):
                if (length == 0):
                    continue
                else:
                    return length
            else:
                length += 1

        return length
```