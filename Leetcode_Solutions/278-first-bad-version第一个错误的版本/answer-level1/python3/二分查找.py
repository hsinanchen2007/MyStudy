```
class Solution:
    def firstBadVersion(self, n):
        i,j=2,n
        while i<=j:
            k=(i+j)>>1
            if not isBadVersion(k):
                i=k+1
            elif isBadVersion(k-1):
                j=k-1
            else:
                return k
        return 1
```
