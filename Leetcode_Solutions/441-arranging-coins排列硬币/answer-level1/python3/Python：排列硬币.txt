### 解题思路
直接求等差数列
结果退位保留

### 代码

```python3
class Solution:
    def arrangeCoins(self, n: int) -> int:
        return int((0.25+2*n)**0.5-0.5)
```