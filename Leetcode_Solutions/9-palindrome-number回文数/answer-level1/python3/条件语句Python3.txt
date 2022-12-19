### 解题思路
条件语句的运用而已，负数肯定不是回文数，10以内的正整数肯定是回文数.......
### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        elif 0<=x<10:
            return True
        else:
            x=str(x)
            y=str(x)[::-1]
            if x==y:
                return True
            else:
                return False
```