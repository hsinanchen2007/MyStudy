### 解题思路
看了官方的动态规划法，发现自己之前就是个智障。。特此更改并记录

### 代码

```python
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        l=[0,1,2,3]
        for i in range(4,n+1):
            l.append(l[i-1]+l[i-2])
        return l[n]
```