### 解题思路
先对输入x进行判断是否大于为负数,在x是正数的情况下将x转换成字符串,并使用srt.[::-1]截取进行颠倒在通int()转换回int类型,在x是负数的情况下和正数一样只是在int转换成str是去除-号,在颠倒结束后在str转换成int时补上,并在返回值进行判断如果溢出就不返回颠倒好的c,返回0.

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        if x>0:
            b=str(x)
            b=b[::-1]
            c=int(b)
            if 0<c<2147483647:
                return c
        else :
            b=str(-x)
            b=b[::-1]
            c=-int(b)
            if -2147483648<c<0:
                return c
        return 0
```