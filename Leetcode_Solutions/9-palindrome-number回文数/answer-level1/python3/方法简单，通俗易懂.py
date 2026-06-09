### 解题思路

先分三类，之后通过index计算

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        elif x == 0:
            return True
        else:
            count = 0
            str_val = str(x)
            for i in range (len(str_val)):
                if int(str_val[i]) == int(str_val[-i-1]):
                    count += 1
            if count == len(str_val):
                return True
            else:
                return False

```