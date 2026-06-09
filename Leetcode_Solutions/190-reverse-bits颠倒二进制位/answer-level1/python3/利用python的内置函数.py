代码如下：
```python3
class Solution:
    def reverseBits(self, n: int) -> int:
        return int("0b"+str(bin(n))[2:].rjust(32,'0')[::-1],2)
        
```
