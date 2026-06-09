### 解题思路
解题思路

思路一：
一开始，想到就是递归。每次拆成一半来计算，递归终止条件就是n==1。
但是这样算法Pow(2, 4) = 2 * 2 * 2 * 2
算法时间复杂度：O(n)

能不能继续优化，对于O(n)的时间复杂度，继续优化下一个目标就是O(logn)。那么就要想到二分法。

思路二：
每次拆成一半（或者一半 * x)，只需要计算一半即可。





代码实现

python代码

思路一代码

class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if n < 0:
            return 1/self.myPow(x, -n)
        if n == 1:
            return x
        if n == 2:
            return x*x
        if n % 2 == 0:
            return self.myPow(x, n//2) * self.myPow(x, n//2)
        else:
            return self.myPow(x, n//2) * self.myPow(x, n//2) * x


class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if n < 0:
            return 1/self.myPow(x, -n)
        if n == 1:
            return x


        half = self.myPow(x, n//2)
        residual = self.myPow(x, n%2)
        return half * half * residual

### 代码

```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if n < 0:
            return 1/self.myPow(x, -n)
        if n == 1:
            return x

        half = self.myPow(x, n//2)
        residual = self.myPow(x, n%2)
        return half * half * residual
```