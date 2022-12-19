### 解题思路
- 只检查一半数量的字符；
- 不是'a'的字符就赋值为'a'，
- 将最后一个字符赋值为'b'。

### 代码

```python
class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        length = len(palindrome)
        for i in range(length // 2):
            if palindrome[i] != 'a':
                return palindrome[:i] + 'a' + palindrome[i + 1:]
        return palindrome[:-1] + 'b' if palindrome[:-1] else ''
```