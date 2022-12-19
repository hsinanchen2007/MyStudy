### 解题思路
这道题最快的解法是用递归也就是说：
（1）a^n = a^(n - 1) \* a^(n - 1), a为偶数
（2）a^n = a^(n - 1) \* a^(n - 1) \* a, a为奇数
trick: 使用位运算（&, ^, <<, >>）比基础运算（+, -, *, /）效率要提高很多。

### 代码

```python
class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        def func(x, n):
            if n == 0:
                return 1
            if x == 0:
                return 0
            temp = func(x, n >> 1)
            if n & 1: # n为奇数
                return temp * temp * x
            else: # n为偶数
                return temp * temp
        if n >= 0:
            res = func(x, n)
        else:
            res = 1 / func(x, -n) 
        return res

    def myPow_2(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        def func(x, n):
            product = 1
            for _ in range(n):
                product *= x
            return product
        if n >= 0:
            res = func(x, n)
        else:
            res = 1 / func(x, -n)
        return res
```