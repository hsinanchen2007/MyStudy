1. 字符串处理
```
class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        binary, string = bin(n)[2:], ''
        # 32 bits
        binary = (32-len(binary)) * '0' + binary
        for i in binary[::-1]:
            string += i
   
```

2. 位运算
```
"""
其实跟上一个差不多, 但是用了位运算
例如 1010, 我们如果仅补4位的话
(1) 1010 最后一位 0 -> string = '0'
1010 >> 1 = 101
(2) 101 最后一位 1 -> string = '01'
101 >> 1 = 10
(3) 10 最后一位 0 -> string = '010'
10 >> 1 = 1
(4) 1 => string '0101'
"""
class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        string, length = '', 32
        while(length > 0):
            string += bin(n)[2:][-1] if n is not None else '0'
            n = n >> 1
            length -= 1
        return int(string, base = 2)

print Solution().reverseBits(12)
```
