### 解题思路
本代码使用while循环实现，中间主要使用分治算法也就是 x *= x
该代码的特点是使用了位运算快速完成
如果n的二进制当前位为1，则将该结果乘上当前位权值，之后使用 x *= x 将x权值变为下一高位所代表的权值，同时使用左移运算 n >>= 1，将n左移1位，与权值变化同步，之后再进入循环
由于使用较为贴近机器的位运算，代码在执行时间上会有所优化


### 代码

```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            x = 1 / x
            n = -n
        pow = 1
        while n:
            if n & 1:
                pow *= x
            x *= x
            n >>= 1
        return pow
```