### 解题思路
此处撰写解题思路
'{:b}'.format(11)   1011

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return '{:b}'.format(int(a,2)+int(b,2))
```