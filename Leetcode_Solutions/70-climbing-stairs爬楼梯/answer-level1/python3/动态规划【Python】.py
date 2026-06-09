### 思路

**动态规划**

```
初始条件和斐波那契数列有点区别：dp_0 = 1，dp_1 = 1。

递推公式：fib(n) = fib(n - 1) + fib(n - 2)
```

**时间复杂度:** O(n)
**空间复杂度:** O(1)

##### Python3代码

```python
class Solution:
    def climbStairs(self, n: int) -> int:
        # 初始条件和斐波那契数列有区别
        dp_0, dp_1 = 1, 1
        for _ in range(n):
            dp_0, dp_1 = dp_1, dp_0 + dp_1
        return dp_0
```

### GitHub链接

[Python](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/0070-Climbing-Stairs/0070.py)