### 解题思路
此题与[面试题10- II. 青蛙跳台阶问题](https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/)一样。
这个代码运行平台似乎超过 100 会导致溢出，报错。虽然 python3 不会溢出。

### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2
        t = 3
        f1, f2 = 1,2
        while t<=n:
            f = f1+f2
            f1 = f2
            f2 = f
            t += 1
        return f 
```