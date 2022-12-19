### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def trailingZeroes(self, n: int) -> int:
        res = 0
        while n>=5:
            res += n//5
            n = n//5
        return res
```