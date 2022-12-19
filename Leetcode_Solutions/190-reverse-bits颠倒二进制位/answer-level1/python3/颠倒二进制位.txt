### 解题思路
1. 首先将整数`n`转换成二进制字符串；
2. 将二进制字符串颠倒，如果长度小于32则在后面补0；
3. 将二进制字符串转换成十进制返回；

### 代码

```python3
class Solution:
    def reverseBits(self, n: int) -> int:
        binary = bin(n)
        binary = binary[2:][::-1]
        if len(binary) < 32:
            binary += '0'*(32-len(binary))
        return int(binary, 2)

```