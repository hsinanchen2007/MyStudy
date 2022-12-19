思路：
1.若n为以2为底x为指数的幂(n = 2^x)，整数n的二进制当且仅当只有一个 1 ，其余均为 0，判断整数n二进制包含1的个数即判断n是否为2的幂次方。
2.整数n的二进制除最高位1其余均为0，与n的位数相对应的(n-1)的二进制最高位为0，其余均为1，通过位运算 n 与 (n-1) 判断是否存在重合即判断n是否为2的幂次方。

```
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n >0 and bin(n)[2:].count('1')==1
    
    def isPowerOfTwo1(self, n: int) -> bool:
        return n > 0 and n & (n - 1) == 0 
```
