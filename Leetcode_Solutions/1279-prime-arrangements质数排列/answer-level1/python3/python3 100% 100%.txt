```
class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        def df(n):
            List=[1]*n
            if n<3:
                return 0
            List[0],List[1]=0,0
            for i in range(2,int(n**0.5)+1): 
                if  List[i]==1:
                    List[i*i:n:i] = [0] * len(List[i*i:n:i])
            return sum(List)
        index = df(n + 1)
        summ = 1
        if n == 0:
            return 0
        else:
            for i in range(1, index + 1):
                summ *= i
                summ = summ % (10**9 + 7)
            for i in range(1, n - index + 1):
                summ *= i
                summ = summ % (10**9 + 7)
            return summ
```
