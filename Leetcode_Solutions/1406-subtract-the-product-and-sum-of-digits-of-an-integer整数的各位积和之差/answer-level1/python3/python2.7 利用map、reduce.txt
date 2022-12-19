代码
```
class Solution(object):
def subtractProductAndSum(self, n):
        """
        :type n: int
        :rtype: int
        """
        #from functools import reduce #used in python3
        num=list(map(int, list(str(n))))
        return reduce(lambda x,y:x*y,num)-sum(num)
```
    