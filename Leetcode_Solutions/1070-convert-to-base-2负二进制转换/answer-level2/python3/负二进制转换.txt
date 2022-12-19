### 解题思路
与2进制表示法类似，当能够整除的时候该位为0，否则为1.只是需要修改一下除数的迭代公式（总是取离它最近的一个偶数）

### 代码

```python3
class Solution:
    def baseNeg2(self, N: int) -> str:
        if N == 0:
            return '0'
        res = ''
        while N != 0:
            tmp = N % (-2)
            if tmp == 0:
                res = '0' + res  
            else:
                res = '1' + res  
            N = (N+tmp)/(-2)  
        return res
```