### 解题思路-异或
类似于[第136题](https://leetcode-cn.com/problems/single-number/)；

t由s中所有字符随机组合+额外一个字符；这样s+t中的字符则是由所有s中字符重复2次+额外一个字符；

将这些字符的所有二进制代码异或，最终的结果即是额外一个字符的二进制代码；

### 代码

```python3
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        if len(s) == 0 and len(t) == 1:
            return t[0]
        # 将s+t中所有字符异或
        bitmasks = 0
        for i in range(len(s)):
            bitmasks ^= ord(s[i])
        for i in range(len(t)):
            bitmasks ^= ord(t[i])
        # bitmasks代表新增字符的ASCII码
        return chr(bitmasks)
```