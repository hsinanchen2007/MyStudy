### 解题思路
先转换成十进制，相加后再转换成二进制

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return bin(int(a, base=2) + int(b, base=2))[2:]
```