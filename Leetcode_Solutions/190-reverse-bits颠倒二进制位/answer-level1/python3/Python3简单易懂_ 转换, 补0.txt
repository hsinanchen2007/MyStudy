### 解题思路
主要就是利用好这几个接口: bin, reverse, join, int

注意由于输入的数转换后不一定有32位, 要补0补到32位

### 代码

```python3
class Solution:
    def reverseBits(self, n: int) -> int:
        binary_str = bin(n)[2:]
        L = list(binary_str)
        L.reverse()
        while len(L) < 32: # 补0
            L.append('0')
        binary_str = ''.join(L)
        return int('0b' + binary_str, 2)
```