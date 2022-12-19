
```python []
class Solution:
    def numSquares(self, n: int) -> int:
        if n==0:
            return 0
        
        num2res = {}
        can = set()
        for x in range(1,n+1):
            temp = x**2
            if temp>n:
                break
            num2res[temp] = 1
            can.add(temp)
        
        if n in num2res:
            return num2res[n]
        while n not in num2res:
            new_num2res = {x:num2res[x] for x in num2res}
            
            for x in new_num2res:
                for y in can:
                    if x+y<n:
                        num2res[x+y] = min([new_num2res[x+y],new_num2res[x]+1]) if (x+y) in new_num2res else new_num2res[x]+1
                    if x+y == n:
                        return min([new_num2res[x+y],new_num2res[x]+1]) if (x+y) in new_num2res else new_num2res[x]+1
            
        
        
        
    
```

