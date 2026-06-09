### 代码
```python
class Solution:
    def exchangeBits(self, num: int) -> int:
        return ((num>>1)&0x55555555) | ((num<<1)&0xaaaaaaaa)
```