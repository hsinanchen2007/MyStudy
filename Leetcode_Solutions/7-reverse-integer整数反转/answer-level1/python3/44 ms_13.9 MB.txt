
```python [
    def reverse(self, x: int) -> int:
        strx = str(x)
        n = len(strx)
        strxx =''
        if x >= 0:   
            for i in range(n):
                strxx = strx[i] + strxx             
            return int(strxx) if int(strxx)<= 2147483647 else 0
        else:
            for i in range(1,n):
                strxx = strx[i] + strxx
            return -int(strxx) if -int(strxx)>= -2147483648 else 0

]

```
