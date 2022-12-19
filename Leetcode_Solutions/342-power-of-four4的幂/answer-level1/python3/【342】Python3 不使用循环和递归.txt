### 解题思路
一个数n是2的幂满足：bin(n) & bin(n-1)得0
因为 n的二进制表示为10000...0  n-1的二进制表示为01111...1

一个数x是4的幂满足：是2的幂 + 二进制表示长度为奇数
如 4-100 16-10000 64-1000000

### 代码

```python3
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        #小于等于0的数非4的幂
        if num <= 0:
            return False
        #2的幂 + 二进制长度为奇数
        return (not num & (num-1)) and (len(bin(num)) % 2 != 0)
```