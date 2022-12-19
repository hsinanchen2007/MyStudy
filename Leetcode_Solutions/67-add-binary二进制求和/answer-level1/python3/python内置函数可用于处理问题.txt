### 解题思路
如代码，int(a,2)表示a是二进制数时将其变为十进制数

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return bin(int(a,2)+int(b,2))[2:]
```