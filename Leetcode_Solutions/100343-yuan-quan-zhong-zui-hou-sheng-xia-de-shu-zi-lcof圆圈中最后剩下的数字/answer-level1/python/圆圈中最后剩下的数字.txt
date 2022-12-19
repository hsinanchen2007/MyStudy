### 解题思路
和剑指offer上面孩子们的游戏一样

### 代码

```python
class Solution(object):
    def lastRemaining(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        if n<1 or m<1:
            return -1
        if n == 1:
            return 0
        value = 0
        for index in range(2,n+1):
            currentvalue = (value + m)%index
            value = currentvalue
            
        return value
```