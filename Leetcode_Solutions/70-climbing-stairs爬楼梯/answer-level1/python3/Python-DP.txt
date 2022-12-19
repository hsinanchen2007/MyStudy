code
```
class Solution:
    def climbStairs(self, n: int) -> int:
        result=[0,1,2]
        for i in range (3,n+1):
          result.append(result[i-1]+result[i-2])
        return result[n]
```