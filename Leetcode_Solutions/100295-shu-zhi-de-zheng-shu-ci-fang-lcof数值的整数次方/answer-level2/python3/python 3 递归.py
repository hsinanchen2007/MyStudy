### 解题思路
递归提高效率

### 代码

```python
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x==0 and n<=0:return -1#异常输入
        if n==0:return 1
        res=1
        abs_n=abs(n)
        def helper(x,n):
            if x==1: return 1
            if n==1: return x
            if n%2==0:
                return helper(x*x,n/2)
            else:
                return x*helper(x,n-1)

        res=helper(x,abs_n)
        return res if n>0 else 1/res



```