### 解题思路
- isalnum():判断字符是否由字母和数字构成的方法；

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        new = ''
        for ch in s:
            if ch.isalnum():
                new += ch.lower()
        return new == new[::-1]
       
```