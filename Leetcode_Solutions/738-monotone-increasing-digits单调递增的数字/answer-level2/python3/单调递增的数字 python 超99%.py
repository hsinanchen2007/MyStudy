> 思路：每次从右往左便历，遇到第一处递增就停下，然后将前一位减1，后面所有位置为9；循环往复，直到序列从左到右是递增的。
```python
class Solution:
    def monotoneIncreasingDigits(self, N: int) -> int:
        
        N = list(map(int,str(N)))
        
        i = len(N)-1
        while i >= 1:
            if N[i-1] > N[i]:
                N[i-1] = N[i-1]-1
                N[i] = 9
                while i+1 < len(N):
                    N[i+1] = 9
                    i = i+1
                i = len(N)-1
            else:
                i = i-1
                
        return int(''.join(map(str,N)))
```