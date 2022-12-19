```
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        n1 = m + n - 2
        k = min(m-1,n-1)
        ji1,ji2 = 1,1
        for i in range(n1-k+1,n1+1):
            ji1 *= i
        for j in range(1,k+1):
            ji2 *= j
        #print(n1,k)	
        return(int(ji1/ji2))

```
