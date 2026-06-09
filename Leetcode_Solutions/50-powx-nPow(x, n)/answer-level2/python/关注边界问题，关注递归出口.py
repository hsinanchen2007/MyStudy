### 解题思路
注意边界条件：
* n < 0 时，要主要先根据数学定义进行倒置，再进行计算；
* 为递归/分治编写出口条件；

### 代码

```python
class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n == 0:
            return 1
        if n == 1:
            return x
        if n < 0:
            return 1 / self.myPow(x, -n)

        if n % 2 == 0:
            # 偶数
            result = self.myPow(x, n/2)
            return result * result
        else:
            result = self.myPow(x, (n-1)/2)
            return result * x * result
```