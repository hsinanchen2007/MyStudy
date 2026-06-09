### 解题思路
慢就慢吧

### 代码

```python3
class Solution:
    def hammingWeight(self, n: int) -> int:
        return bin(n).count('1')
```