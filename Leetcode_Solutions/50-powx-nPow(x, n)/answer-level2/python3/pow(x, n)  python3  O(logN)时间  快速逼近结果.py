### 解题思路
首先判断n的取值
1. 如果n>0,直接调用method方法计算；
2. 如果n=0，方法返回1；
3. 如果n<0，则使用n的相反数调用method方法，最后返回method结果的倒数

写一个method方法来计算x的n次方(n>0):
如果n=1，直接返回x
用start记录下初始的x
用temp记录已经乘了多少次
- 当temp小于n时：先记录下此时x的值；x = x的平方；temp = temp乘2；然后循环这一步
- 当temp大于n时：x = x/last_x；temp = temp / 2；即使上一步中x和temp的结果后退一步，避免结果多乘。
- 考虑x的边界情况，x = 0 和 或 超过2**31-1时，返回0，或者正无穷
- 递归调用method，返回x乘以剩下没乘的幂次



### 代码

```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n > 0:
            return method(x, n)
        elif n == 0:
            return 1
        else:
            if method(x, -n) is float("inf"):
                return 0
            else: return 1/method(x, -n)
        

def method(x, n):
    if n == 1: return x
    temp = 1
    start = x
    while temp < n:
        last_x = x
        x *= x
        temp *= 2
    if x == 0: return 0
    if x >= 2147483647: return float("inf")
    x = x / last_x
    temp = temp / 2
    return x * method(start, n-temp)
    
```