### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n<0:
            x=1/x
            n=-n
        ans=1
        while n:
            if n&1==1:
                ans*=x

            x*=x
            n>>=1
        print(x)
        return ans
    
```