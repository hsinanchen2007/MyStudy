### 解题思路
首先，说下回文串的含义，回文串即正序和反序都是一样的字符串
其次，解决本题的思路为先将其转换为小写形式，再剔除字符串中与数字和字母无关的符号组成只有字母和数字的新字符串，最后判断新字符串的正序和反序是否一致即可。

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        if not s:
            return True
        s = s.lower()
        n = len(s)
        s_new = ''
        for i in range(n):
            if s[i].isdigit() or s[i].isalpha():
                s_new += '{}'.format(s[i])
        return s_new == s_new[::-1]
```