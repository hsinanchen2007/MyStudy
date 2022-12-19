总结评论区几种常见写法：
```python []
class Solution:    #转化为字符串，切片
    def reverse(self, x: int) :
        x_str=str(x)
        if x>=0:
            x_str=x_str[::-1]
            x=int(x_str)
        else:
            x_str=x_str[1:][::-1] #注意此处不可为[1::-1]
            x=int(x_str)
            x=-x
        return x if -(1<<31)<=x<=(1<<31)-1 else 0
```
```python []
class Solution: #转化为字符串，
    def reverse(self, x: int) :
        if x==0:
            return 0
        str_x=str(x)
        x=''
        if str_x[0]== '-':
            x+='-'
        x +=str_x[len(str_x)-1::-1].lstrip('0').rstrip('-')
        x=int(x)
        if -2**31<x<2**31-1:
            return x
        return 0
```
```python []
class Solution: #直接int运算
    def reverse(self, x: int) :
        y,xo=abs(x),0
        range_max=(1<<31)-1 if x>0 else 1 <<31
        while y!=0:
            xo=xo*10+y%10
            if xo>range_max: return 0
            y//=10
        return xo if x>0 else -xo
```
