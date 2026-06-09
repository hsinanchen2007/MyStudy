import math

class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        out = []
        low_base = math.floor(math.log10(low))
        high_base = math.ceil(math.log10(high))
        num = list(range(1, 10))
        for i in range(low_base, high_base + 1):
             for j in range(len(num)-i):
                 curr = sum([num[j+k]*(10**(i-k)) for k in range(i+1)])
                 if curr >= low and curr <= high:
                     out.append(curr)
        return out 
