**方法一：**
    首先献上Python3 1行AC代码，利用递归 + 短路 + 叠加。
*    *注：在 python 中，布尔 **and** - 如果 x 为 False，x and y 返回 False，否则它返回 y 的计算值。*
```
class Solution:
    def sumNums(self, n: int) -> int:
        return n and n + self.sumNums(n - 1)
```
**方法二：**
    核心是通过位运算实现乘法和除法操作，当然因为题目限制问题，需要通过短路原理修改一下。
    易知，`1 + 2 + ... + n = (1 + n) * n / 2`，其中，乘法由multi(a, b)函数实现，关于如何递归实现`a*b`，大家可以去网上搜一搜详细的讲解，`/2`右移一位即可实现，代码如下。
```
class Solution:
    def sumNums(self, n: int) -> int:
        def multi(a, b):
            return b and ((b & 1 and a) + multi(a << 1, b >> 1))
        return (multi(1 + n, n)) >> 1
```


