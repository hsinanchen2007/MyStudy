```
超时
class Solution:
    def countPrimes(self, n: int) -> int:
        prim = []
        def isprim(v):        
            for i in prim:
                if i*i>v:
                    break
                if v % i == 0:
                    return False
            return True
                
        if n<2:
            return 0
        for i in range(2, n):
            if isprim(i):
                prim.append(i)
        return len(prim)

```
```
代码块
class Solution:
    def countPrimes(self, n: int) -> int:
        m = [i for i in range(2, n)]
        i = 0        
        while(i<len(m)):
            j = m[i]
            for k in range(j*2, n, j):
                try:
                    m.remove(k)
                except:
                    pass
            i += 1
        return len(m)
    
```
```
class Solution:
    def countPrimes(self, n: int) -> int:
        m = [1] * n
        c = 0
        i = 2
        while i*i<n:
            if m[i]:
                c += 1
            for j in range(i*i, n, i):
                m[j] = 0
            i += 1
        for j in range(i, n):
            if m[j]:
                c += 1
        #print(m)
        return c
```
