### 解题思路
第一次写1行代码，其实就是减少了行数而已，想法很直接

### 代码

```python3
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        return float(num**0.5)==int(num**0.5)
            
```