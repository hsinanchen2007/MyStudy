### 解题思路
此处撰写解题思路
h(0) = 1
h(1) = 1
h(n) = h(0)*h(n-1) + h(1)*h(n-2) + ......+ h(n-2)*h(1) + h(n-1)*h(0)
符合卡特兰数的特征，直接数学计算
### 代码

```python3
class Solution:
    def numTrees(self, n: int) -> int:
        if n == 0:
            return 1
        up = self.factorial(2*n)
        down_part = self.factorial(n)
        return up // (down_part*down_part*(n+1))
    def factorial(self,n):
        res = 1
        for i in range(1,n+1):
            res *= i
        return res
```