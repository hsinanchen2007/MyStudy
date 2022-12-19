```python []
class Solution(object):
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """
        l,r=0,n
        while l<=r:
            m=(l+r)//2
            if (m**2+m)*0.5<=n and (m**2+3*m+2)*0.5>n:
                return m
            elif (m**2+m)*0.5<n:
                l=m+1
            elif (m**2+m)*0.5>n:
                r=m-1
```
