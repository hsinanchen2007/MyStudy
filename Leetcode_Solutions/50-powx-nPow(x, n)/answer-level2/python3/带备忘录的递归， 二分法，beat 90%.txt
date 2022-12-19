### 解题思路
带备忘录的递归， 二分法
不带备忘录会超时

### 代码

```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n<0:
            n=-n
            x= 1/x
        # 带备忘录的递归
        memo = {}
        memo[0] = 1 # 边界条件
        memo[1] = x # 边界条件
        def pow(n):
            if n in memo:
                return memo[n]
            tmp = pow(n//2) * pow(n-n//2) # 转移方程
            memo[n] = tmp
            return tmp
        return pow(n)
        
```