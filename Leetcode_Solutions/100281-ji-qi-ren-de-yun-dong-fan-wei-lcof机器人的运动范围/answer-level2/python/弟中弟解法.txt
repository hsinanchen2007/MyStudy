### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def movingCount(self, m, n, k):
        """
        :type m: int
        :type n: int
        :type k: int
        :rtype: int
        """
        vis=set([(0,0)])
        for i in range(m):
            a,b=divmod(i,10)
            for j in range(n):
                c,d=divmod(j,10)
                if a+b+c+d<=k:
                    if (i-1,j) in vis or (i,j-1) in vis:
                        vis.add((i,j))
        return len(vis)
```