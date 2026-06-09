```
class Solution(object):
    def numPrimeArrangements(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n==1:return 1
        if n==2:return 1
        if n==3:return 2
        zhi = 2
        res = 1
        for i in range(4,n+1):
            for j in range(2,int(i**0.5)+1):
                if i%j==0:
                    break
            else:
                zhi += 1
        for i in range(1,zhi+1):
            res *= i
        for i in range(1,n-zhi+1):
            res *= i
        return res%(10**9+7)
```
