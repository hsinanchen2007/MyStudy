
### 代码

```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        an=abs(n)
        ans=1
        while an>0:           
            an,k=divmod(an,2)
            if k==1:
                ans*=x
            x*=x 
        if n<0:
            return 1/ans       
        return ans
```