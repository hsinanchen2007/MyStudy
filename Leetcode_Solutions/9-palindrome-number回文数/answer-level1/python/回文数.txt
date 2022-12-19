### 解题思路
进阶

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        if x < 10:
            return True
        if x % 10 == 0:
            return False
        
        ori = x
        res = 0
        while True:
            p = x // 10
            q = x % 10
            if q == 0 and p == 0:
                break
            else:
                x = p
            res = res*10
            res += q

        if res == ori:
            return True
        else:
            return False

        
```