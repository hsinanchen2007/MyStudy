### 解题思路
定义状态f(n): 到n阶楼梯的方法数
最后一步： 比如到10阶的方法数 = 到9阶的方法数 + 到8阶的方法数 （因为每次仅可以爬1或2阶）
转移方程： f(n) = f(n-1) + f(n-2)
初始值： f(1) = 1 f(2) = 2
### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        if n < 3:
            return n
        f = [0] * (n + 1)  # [0, n]
        f[1], f[2] = 1, 2
        for i in range(3, n + 1):
            f[i] = f[i - 1] + f[i - 2]
        return f[n]
```

一个数组也没费多少空间，感觉没必要钻牛角尖共享两个变量手动传递上次状态。 
要不然、、使劲钻😄，可以再写个方法用尾递归的方式：

```python3
class Solution:
    def climb(self,n, fn_2, fn_1, toStep):
        fn = fn_2 + fn_1
        if n == toStep:
            return fn
        return self.climb(n, fn_1, fn, toStep + 1)


    def climbStairs(self, n: int) -> int:
        if n < 3:
            return n
        return self.climb(n, 1, 2, 3)
```