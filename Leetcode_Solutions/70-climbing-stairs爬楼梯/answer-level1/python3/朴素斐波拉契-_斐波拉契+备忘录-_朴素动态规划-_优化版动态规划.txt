
### 朴素斐波拉契
```python
#@author:leacoder
#@des:  斐波拉契 无优化 爬楼梯

'''
递推公式 f(n) = f(n-1) + f(n-2)
就是一个Fibonacci, 这里 是不做任何优化的递归实现的斐波拉契
有意地将 Fibonacci 的递归实现单独写为一个方程
'''

class Solution:
    def climbStairs(self, n: int) -> int:
        return self.recursive(n)

    # 递归
    def recursive(self, n:int) -> int:
        # 递归终止条件
        if n == 0 or n == 1 or  n == 2:
            return n
        return self.recursive(n-1) + self.recursive(n-2)
```

### 斐波拉契+备忘录

 使用 字典 存储 斐波拉契数列 递归中重复计算项

```python
#@author:leacoder
#@des:  斐波拉契 备忘录  爬楼梯

'''
递推公式 f(n) = f(n-1) + f(n-2)
就是一个Fibonacci, 这里 使用 字典 存储 斐波拉契数列 递归中重复计算项
'''

class Solution:
    def climbStairs(self, n: int) -> int:
       self.value_dict = dict()     # 字典
       return self.recursive(n)

    # 递归
    def recursive(self, n:int) -> int:
        # 递归终止条件
        if n == 0 or n == 1 or n == 2:
            return n
        if n in self.value_dict:
            return self.value_dict[n]
        result = self.recursive(n - 1) + self.recursive(n - 2)
        self.value_dict[n] = result     # 存入字典
        return result
```

### 朴素动态规划

使用dp方程，不做存储优化

```python
#@author:leacoder
#@des:  动态规划 计算所有 f(n) 爬楼梯

'''
递推公式 f(n) = f(n-1) + f(n-2)
计算所有 f(n),空间复杂度 O(n) 时间复杂度O(n)

动态规划
a、重复子问题
当前台阶有 上1级跨1个台阶到达 或 上2级跨2个台阶到达
b、dp状态
dp[i]  到第i级台阶的不同走法
c、dp方程
dp[i] = dp[i-1] + dp[i-2]
初始化：
dp[0] = 1
dp[1] = 1
# 便于 i = 2 的推导

'''
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 0:
            return 1
        dp = [0]*(n+1)
        dp[0], dp[1] = 1, 1
        for i in range(2, n+1):
            dp[i] = dp[i - 1] + dp[i - 2]
        return dp[-1]
```

### 优化版动态规划
对存储优化，不存储所有dp[i]状态

```python
#@author:leacoder
#@des:  动态规划 优化版 爬楼梯

'''
相对于动态规划 无优化会计算所有 dp[i]，这里每次迭代之和dp[i-1]和dp[i-2]有关
只存储当前以及上一个状态数据,空间复杂度 O(1) 时间复杂度O(n)
dp方程dp[i] = dp[i-1] + dp[i-2]，不必计算所有dp[i]
使用 f0 f1 分别为 上一状态， 当前状态
'''
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 0:
            return 0
        f0 = f1 = 1
        for i in range(1, n):
            f0, f1 = f1,f0 + f1
        return f1
```