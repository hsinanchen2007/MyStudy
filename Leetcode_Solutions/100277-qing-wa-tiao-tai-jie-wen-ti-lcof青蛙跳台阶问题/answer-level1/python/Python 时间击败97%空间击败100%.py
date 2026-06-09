![image.png](https://pic.leetcode-cn.com/096465ba4fa515ea585d417ad384ffa34f67af12a2404251ea543eaac537b6a5-image.png)

```
class Solution(object):
    def __init__(self):
        self.d = {0:1,1:1,2:2}  #用来存放计算结果，省去重复递归
        for i in xrange(3,101):
            self.d[i] = (self.d[i-1] + self.d[i-2]) % 1000000007

    def numWays(self, n):
        """
        :type n: int
        :rtype: int
        """
        return self.d[n]
```
