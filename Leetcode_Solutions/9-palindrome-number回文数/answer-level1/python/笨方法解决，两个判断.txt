### 解题思路
笨方法，如果x<0，一定不是
否则，x和x的逆序相等，回文，否则不是

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        x_str = str(x)
        if x_str != x_str[::-1]:
            return False
        else:
            return True
```