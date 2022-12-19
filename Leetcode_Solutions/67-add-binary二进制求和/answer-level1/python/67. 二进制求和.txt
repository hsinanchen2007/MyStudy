### 解题思路
转换为十进制后相加，再转换为二进制，返回结果。

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        I1 = int(a, 2)
        I2 = int(b, 2)
        return '{:b}'.format(I1+I2)
```