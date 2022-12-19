### 解题思路
照公式递归即可

### 代码

```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x==0:
            return 0
        if n==0:
            return 1
        if n==1:
            return x
        if n>=0:
            return self.myPow(x*x,n//2) if n%2==0 else self.myPow(x*x,n//2)*x
        if n<0:
            return self.myPow(1/(x*x),(-n)//2) if (-n)%2==0 else self.myPow(1/(x*x),(-n)//2)*(1/x)
```