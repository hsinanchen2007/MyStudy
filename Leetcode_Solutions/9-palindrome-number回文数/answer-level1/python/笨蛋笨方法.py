### 解题思路
思路来自第7题的数字反转，但特意绕过str处理方法，采用/10取余，余数*10+下一次/10的余数，一步步将整个数字翻转过来后进行判断。
提前判断小于0，等于0的情况可以加速。

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        if x == 0:
            return True
        if x > 0:
            if x % 10 == 0:
                return False
            y, res = x, 0
            while y != 0:
                res = res * 10 + y % 10
                y //= 10
            if x == res:
                return True
            else:
                return False
```