嘿嘿嘿

### 代码

```python3
class Solution:
    def canWinNim(self, n: int) -> bool:
        return bin(n)[-2:] != "00"
```