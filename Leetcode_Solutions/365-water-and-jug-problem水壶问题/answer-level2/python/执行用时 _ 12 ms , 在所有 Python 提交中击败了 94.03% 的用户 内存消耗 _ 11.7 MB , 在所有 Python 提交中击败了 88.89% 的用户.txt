### 解题思路
此处撰写解题思路
m*x+n*y=z
在保证y>x的条件下，求最大公约数的过程。只要z是最大公约数的倍数，就能够把x和y组合为z.
### 代码

```python
class Solution(object):
    
    def func(self,a,b):
        x = a % b
        while (x != 0):
            a = b
            b = x
            x = a % b
        return b    
    def canMeasureWater(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """ 
       	if x+y ==z or z==0:
		return True
        if x+y < z :
            return False
        #保证是 y>x ;不满足的话就进行交换
        if x>y:
            temp = x
            x = y
            y = temp
        if x==0:
            return y ==z
        #寻找最大公约数
        return (z % self.func(x, y))==0
```