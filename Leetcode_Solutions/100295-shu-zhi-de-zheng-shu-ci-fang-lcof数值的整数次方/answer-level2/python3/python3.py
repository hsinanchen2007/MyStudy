### 解题思路

### 代码

```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n==0:
            return 1
        elif n==1:
            return x
        elif n==-1:
            return 1/x

        return self.myPow(x,n//2)**2*self.myPow(x,n%2)
        
```