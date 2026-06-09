### 解题思路
两行，int，bin转换

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        bi = "0b"
        return bin(int(bi+a,2)+int(bi+b,2))[2::]
```