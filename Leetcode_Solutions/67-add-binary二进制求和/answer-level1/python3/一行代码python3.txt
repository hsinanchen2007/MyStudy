### 解题思路

int函数的转化为十进制相加再转化为二进制

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return bin(int(a,2)+int(b,2))[2:]
```