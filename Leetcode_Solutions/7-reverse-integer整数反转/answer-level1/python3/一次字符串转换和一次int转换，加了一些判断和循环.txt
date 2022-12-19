### 解题思路
主要通过一次字符串转换和一次int转换对整个问题进行求解。用的都是简单的函数，可能效率确实低了些。。还要向高手学习。
### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        b=x
        x=list(str(x))
        a=len(x)
        out=[]
        if b>0:
            for i in range(0,a,1):
                out.append(x[a-i-1])            
            outx=int(''.join(out))
        elif b==0:
            return(0)
        else:
            for i in range(a-1,0,-1):
                out.append(x[i])            
            outx=int(''.join(out))
            outx=-1*outx
        if outx in range(-2**31,2**31):
            return outx
        else:
            return(0)
```