根据数据范围10的六次方，所以直接记录二十以内的质数就可以

```python
class Solution:
    def countPrimeSetBits(self, L: int, R: int) -> int:
        zhi = [0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1]
        n=0
        for i in range(L,R+1):
            q=bin(i)
            s=q.count('1')
            if zhi[s]==1:
                n+=1
            
        return n
```