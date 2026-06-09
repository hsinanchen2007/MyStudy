### 解题思路
先将整数转化为字符串，再将其反转，并与反转之前的字符串进行比较，
若相同，则是回文
否则，不是。

### 代码

```python3
class Solution:
    def isPalindrome(self, num: int) -> bool:
        s1 = str(num)
        s2 = reversed(s1)
        s2 = ''.join(_ for _ in  list(s2))
        if s1 == s2:
            return True
        else :
            return False
```