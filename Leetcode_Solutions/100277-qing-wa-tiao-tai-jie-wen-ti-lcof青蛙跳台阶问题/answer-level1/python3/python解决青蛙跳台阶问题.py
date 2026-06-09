### 解题思路
同爬楼梯问题类似

### 代码

```python
class Solution(object):
    def numWays(self, n):
        """
        :type n: int
        :rtype: int
        """
        climb = {}
        climb[0] = 1
        climb[1] = 1
        climb[2] = 2
        for i in range(3,n+1):
            climb[i] = climb[i-1] + climb[i-2]
        return climb[n] % 1000000007
```