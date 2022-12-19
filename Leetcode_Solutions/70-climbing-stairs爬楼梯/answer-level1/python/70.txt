### 解题思路
1、同青蛙跳台阶问题
2、斐波那契数列

### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 0:
            return 1
        if n in [1, 2]:
            return n
        a, b = 1, 2
        if n > 2:
            for i in range(2, n):
                result = a + b
                a, b = b, result
        return result
```