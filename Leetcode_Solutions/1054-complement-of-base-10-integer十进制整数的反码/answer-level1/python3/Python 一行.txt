### 解题思路
一行求解

### 代码

```python3
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        return int("".join('0' if i == '1' else '1' for i in bin(N).replace('0b', '')), 2)
```