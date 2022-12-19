```
class Solution:
    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        ans = []
        for x in range(1,1001):
            if customfunction.f(x,1)<=z and customfunction.f(x,1000)>=z:
                #bi search y
                i = 1
                j = 1000
                while i<=j:
                    m = (i+j)//2
                    if customfunction.f(x,m)>z:
                        j = m-1
                    elif customfunction.f(x,m)<z:
                        i = m+1
                    else:
                        ans.append([x, m])
                        break
        return ans
```

