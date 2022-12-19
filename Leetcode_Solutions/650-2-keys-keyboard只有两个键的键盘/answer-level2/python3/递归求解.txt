
```python []
class Solution:
    def minSteps(self, n: int) -> int:        
        def count_num(n):
            a=0
            if n==1:
                return 0
            else:
                for i in range(n//2,2,-1):
                    if n%i==0:
                        a=i
                        break
                if a==0:
                    return n 
                else:
                    return int(n/a)+count_num(a)
            
        return count_num(n)
```


