N+反码的值的二进制应该为'11...1'长度就是N的二进制数的长度n，其和值就是 1+2^1+...+2^(n-1) = 2^n-1
直接带入计算即可
```
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        return 2**(len(bin(N))-2)-1-N
```