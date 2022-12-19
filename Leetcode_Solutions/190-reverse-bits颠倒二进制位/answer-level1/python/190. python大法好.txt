### 解题思路
1. 十进制到二进制转换。
2. 切片，切掉'0b'，只保留后面部分。
3. zfill补齐32位。
4. 反转。
5. 补上'0b'转换成十进制。

### 代码

```python3
class Solution:
    def reverseBits(self, n: int) -> int:
        return int('0b'+bin(n)[2:].zfill(32)[::-1], 2)
        
```