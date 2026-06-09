### 解题思路
combine(n,k)=[[n]+combine(n-1,k-1)]+[combine(n-1,k)]

### 代码

```python
class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """  
        return sorted(self.digui(n,k))

    def digui(self,n,k):
        if k==1:
            return [[x] for x in range(1,n+1)]
        if k==n:
            return [[x for x in range(1,n+1)]]
        return [x + [n] for x in self.digui(n-1,k-1)]+[x for x in self.digui(n-1,k)]
```