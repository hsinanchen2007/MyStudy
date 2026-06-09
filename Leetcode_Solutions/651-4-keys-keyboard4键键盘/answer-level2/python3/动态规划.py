```
class Solution:
    def maxA(self, N: int) -> int:
        if N<5:
            return N
        m = [i+1 for i in range(N)]
        for i in range(3, N):
            m[i] = m[i-1]+1
            for j in range(i-2):
                m[i] = max(m[i], m[j]*(i-j-1))
        #print(m)
        return m[-1]
            
```
