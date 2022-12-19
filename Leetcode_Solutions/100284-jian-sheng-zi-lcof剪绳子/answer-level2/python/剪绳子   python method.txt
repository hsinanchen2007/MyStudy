### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def cuttingRope(self, n: int) -> int:
        if n <= 3:
            return n-1
        
        a,b = n//3,n%3
        if b == 0:
            return int(math.pow(3,a))
        elif b == 1:
            return int(math.pow(3,a-1)*4)
        else:
            return int(math.pow(3,a)*2)

```



the python method for this problem