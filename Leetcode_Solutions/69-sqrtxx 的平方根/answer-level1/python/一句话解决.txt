python里直接求平方根的方法是x**0.5，也就是求它的0.5次方
然后呢取整函数是int(x)
```
class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        return int(x**0.5)
```


