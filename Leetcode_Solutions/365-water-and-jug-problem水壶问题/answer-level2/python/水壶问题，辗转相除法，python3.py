### 解题思路
题意可以转化为对于方程*ay+bx=z*，求*a*和*b*的整数解问题
当且仅当*z*是*x*和*y*最大公约数的整数倍时，*a*，*b*存在整数解。
这里利用**辗转相除法**求解*x*和*y*的最大公约数

### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        def GCD(a, b):
            a, b = max(a, b), min(a, b)
            while b:
                temp = a%b
                a = b
                b = temp
            return a

        if x + y < z:
            return False
        if x == 0 or y == 0:
            return z==0 or x+y==z
        return z % GCD(x, y) == 0
```