### 解题思路
注意1是3的零次幂，不用特殊处理

### 代码

```python3
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n == 0:
            return False

        flag = True
        while True:
            rest = n
            if n % 3 == 0:
                n //= 3
            if n == 1:
                return True
            if rest == n:
                return False

```