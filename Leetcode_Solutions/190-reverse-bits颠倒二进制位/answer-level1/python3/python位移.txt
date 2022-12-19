### 解题思路

做32次位移运算
直接将每次的余数做2进制转10进制运算
### 代码

```python3
class Solution:
    def reverseBits(self, n: int) -> int:
        count = 32
        result = 0
        while count:
            top = n & 1
            result = result << 1 | top
            n >>= 1
            count -= 1
        return result
```