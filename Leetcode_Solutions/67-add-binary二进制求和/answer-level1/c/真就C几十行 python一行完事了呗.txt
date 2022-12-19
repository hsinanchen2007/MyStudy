### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return bin(int(a, 2) + int(b, 2))[2:]
```