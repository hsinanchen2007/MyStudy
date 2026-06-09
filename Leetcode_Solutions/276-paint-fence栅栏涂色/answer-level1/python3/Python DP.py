```
class Solution:
    def numWays(self, n: int, k: int) -> int:
        one=[0,k,k*(k-1)]
        two=[0,0,k]
        if n<3:
            return one[n]+two[n]
        for i in range(2,n+1):
            one.append(two[-1]*(k-1)+one[-1]*(k-1))
            two.append(one[-2])
        return one[n]+two[n]
```
