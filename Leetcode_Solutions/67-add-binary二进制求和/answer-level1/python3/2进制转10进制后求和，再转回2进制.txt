### 解题思路
2进制-->10进制：从低位到高位，从右到左的索引i(从0开始)，当前值n(1, 0)分别乘以2的i次方的和；
sum(n * 2 ** i)

10进制-->2进制：不断对该数求余，直到商为0，将余数反向排列就是该数的2进制表示

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        if a == b == '0':  
            return '0'
        
        # 分别求a，b的10进制数
        a10, b10 = 0, 0
        for i, v in enumerate(a[::-1]):  # 反向遍历
            a10 += int(v) * 2 ** i
        for i, v in enumerate(b[::-1]):
            b10 += int(v) * 2 ** i
        sum = a10 + b10  # 加和
        
        # 10进制-->2进制
        s = ''
        while sum:
            s += str(sum % 2)
            sum //= 2
        return s[::-1]



```