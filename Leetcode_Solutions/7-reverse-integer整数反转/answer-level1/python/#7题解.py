### 解题思路
利用取余和整除操作，将x反转
注意：由于整除操作//是下整除，所以对负数进行取余与预期不一致，python中取余数为a=x-n*(x//n)。
例如-123%10=7，与预期的结果-3不符，是由于7=-123-10*(-123//10)=-123-10*(-13)



### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        res=0
        x_copy=abs(x)
        while x_copy!=0:
            res=res*10+x_copy%10
            x_copy=x_copy//10
            if -res<-(2**31) or res>(2**31)-1:
                return 0
        return res if x>0 else -res
```