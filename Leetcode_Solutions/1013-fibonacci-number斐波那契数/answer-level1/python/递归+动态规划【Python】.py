### 思路

##### 解法一：递归

```
fib(n) = fib(n - 1) + fib(n - 2)
```

##### Python3代码

```python
class Solution:
    def fib(self, n: int) -> int:
        # solution one: 递归
        if n == 0:
            return 0
        if n == 1:
            return 1
        return self.fib(n - 1) + self.fib(n - 2)
```

##### 解法二：动态规划

**时间复杂度:** O(n)
**空间复杂度:** O(1)

##### Python3代码

```python
class Solution:
    def fib(self, n: int) -> int:
        # solution two: 动态规划
        dp_0, dp_1 = 0, 1
        for _ in range(n):
            dp_0, dp_1 = dp_1, dp_0 + dp_1
        return dp_0
```

### GitHub链接

[Python](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/0509-Fibonacci-Number/0509.py)