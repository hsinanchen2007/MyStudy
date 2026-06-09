```
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ret, index = [1], [0, 0, 0]
        for i in range(n-1):
            ret.append(min(ret[index[0]]*2, ret[index[1]]*3, ret[index[2]]*5))   
            for j in range(3):
                if ret[-1] == ret[index[j]]*[2, 3, 5][j]:
                    index[j] += 1            
        return ret[-1]
```
