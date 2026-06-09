### 解题思路
![image.png](https://pic.leetcode-cn.com/476d877f05007663dbd3e7e0e211eb073f18d0a35dfa914b87bfd5a4e7754383-image.png)

通过2*n这样减少计算量
1. 利用递归
2. 利用迭代

### 代码

```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
    #     if n < 0:
    #         n = -n
    #         return 1/self.fast_pow(x, n)
    #     return self.fast_pow(x, n)
    
    # def fast_pow(self, x, n):
    #     if n == 0:
    #         return 1
    #     if n % 2 == 0:
    #         return self.fast_pow(x * x, n // 2)
    #     return self.fast_pow(x * x, (n-1) // 2) * x

        judge = True
        if n < 0:
            n = -n
            judge = False
        
        final = 1
        while n > 0:
            if n % 2 == 0:
                x *= x
                n //= 2
            final *= x
            n -= 1
        return final if judge else 1/final
```