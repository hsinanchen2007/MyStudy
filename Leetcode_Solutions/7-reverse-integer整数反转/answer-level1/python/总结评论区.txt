

```python []
class Solution:# 转化为字符串
    def reverse(self, x: int) -> int:
        x_str= str(x)
        if x>=0:
            x_str=x_str[::-1]
            x_out=int(x_str)
        if x<0:
            x_str=x_str[1:][::-1]
            x_out=-int(x_str)
        return x_out if-(1<<31) <= x_out <= (1<<31)-1 else 0

```

```python []
class Solution:# 直接运算 耗时36ms
    def reverse(self, x: int) -> int:
        y=abs(x)
        x_out=0
        while y!=0:
            x_out=x_out*10+y%10
            y//=10
        x_out=x_out if x>=0 else -x_out
        return x_out if -1<<31 <=x_out<=(1<<31)-1 else 0

```
