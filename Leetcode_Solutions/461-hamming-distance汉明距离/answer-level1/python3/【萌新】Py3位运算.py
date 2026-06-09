### 解题思路
^位运算符秒解

### 代码

```python3
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        return bin(x ^ y).count('1')
```