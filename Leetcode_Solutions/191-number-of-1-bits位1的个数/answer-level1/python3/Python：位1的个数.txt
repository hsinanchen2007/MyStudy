### 解题思路
是不是位运算会好很多，但我是真玩不来

### 代码

```python3
class Solution:
    def hammingWeight(self, n: int) -> int:
        return sum(1 for i in bin(n)[2:] if i>'0')
```