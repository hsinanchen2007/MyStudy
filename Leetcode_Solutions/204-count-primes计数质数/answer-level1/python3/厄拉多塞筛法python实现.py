```
class Solution:
    def countPrimes(self, n: int) -> int:
        List=[1]*n
        if n<3:
            return 0
        List[0],List[1]=0,0
        for i in range(2,int(n**0.5)+1): 
            if  List[i]==1:
                       List[i*i:n:i] = [0] * len(List[i*i:n:i])
        return sum(List)
```
