最简单的Python3实现
``` python3
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        binary = bin(N)
        newBinary = '0b'
        for i in range(2, len(binary)):
            newBinary += '0' if binary[i] == '1' else '1'
        return int(newBinary, 2)
```
