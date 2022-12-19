### 解题思路
针对任意给出的x，y，z，可以假设用x与y分别往一个很大的容器里倒水和倒出水，那么如果z=m*x+n*y，找到合适的正整数m与n即为所求，其中m与n为负时，往外倒水，为正时，往里倒水。

### 代码

```python
class Solution(object):
    def canMeasureWater(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """
        tmp=self.gcd(x,y)
        if z==0:return True
        if z>x+y:return False
        return z%tmp==0
        
    def gcd(self,x,y):
        if y==0:return x
        return self.gcd(y,x%y)
```