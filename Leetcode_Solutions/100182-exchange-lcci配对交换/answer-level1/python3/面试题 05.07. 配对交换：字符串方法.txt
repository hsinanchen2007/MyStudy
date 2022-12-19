
```python []
class Solution:
    def exchangeBits(self, num: int) -> int:        
        if len(b := bin(num)[2: ]) % 2:
            b = '0' + b
        return int(''.join(j + i for i, j in zip(b[:: 2], b[1:: 2])), 2)
```