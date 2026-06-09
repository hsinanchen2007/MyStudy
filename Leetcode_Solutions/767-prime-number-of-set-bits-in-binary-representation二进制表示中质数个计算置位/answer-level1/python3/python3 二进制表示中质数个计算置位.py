暴力思想，helper函数判断是否为质数
```
class Solution:
    def countPrimeSetBits(self, L: int, R: int) -> int:
        res = 0
        def helper(n):
            if n==1: return False
            for i in range(2,int(n**0.5)+1):
                if n%i == 0:
                    return False
            return True
        for i in range(L,R+1):
            n = bin(i)[2:].count('1')
            if helper(n):
                res+=1
        return res
```
