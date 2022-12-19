### 解题思路
还真就挨个删除

### 代码

```python
class Solution(object):
    def lastRemaining(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        ori=[i for i in range(n)]
        i=0
        # print ori
        while len(ori)>1:
            i=(i+m-1)%len(ori)
            # print 'delete {},第{}个'.format(ori[i],i)
            ori.pop(i)
            # print ori
        return ori[0]
```