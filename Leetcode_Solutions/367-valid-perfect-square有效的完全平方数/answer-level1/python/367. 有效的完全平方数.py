### 解题思路

### 代码

```python3
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        return (num // math.sqrt(num)) * math.sqrt(num) == num
```