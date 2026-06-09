### 解题思路
和第29题类似，采用类似的结构，每次扩大乘数，从而显著减少运算时间。
当然，有一点不太相似，就是需要判断n是否为负数，如果为负数则还要转成正数，二者区别在于temp的初始值不同。

### 代码

```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        ret, a  = 1, x
        if n < 0:
            a, n = 1 / x, -n
        while n > 0:
            temp, i = a, 1
            while n - i >= 0:
                n, ret = n - i, ret * temp
                temp, i = temp * temp, i << 1
        return ret
```