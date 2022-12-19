### 解题思路
变为string 和 list之后

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        b = list(str(x))
        if b[0] == '-':
            d_ = 0
            for i in range(len(b)-1,0,-1):
                d_ = int(b[i])*(pow(10,i-1)) + d_
            if d_ > pow(2,31) - 1:
                return(0) 
            else:
                return(-d_) 
        else:
            d = 0
            for i in range(len(b) - 1, -1, -1):
                d = int(b[i]) * (pow(10, i)) + d
            if d > pow(2, 31):
                return(0) 
            else:
                return(d)
```