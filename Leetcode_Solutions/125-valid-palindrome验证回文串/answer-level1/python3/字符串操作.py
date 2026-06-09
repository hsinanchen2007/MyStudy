### 解题思路
1、字符串变小写
2、循环找是字符数字，存res里
3、反转对比是否回文

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        res = ""
        for i in s:
            if (i >= 'a' and i <= 'z') or (i >= '0' and i <= '9'):
                res += i

        return res[:] == res[::-1]
```