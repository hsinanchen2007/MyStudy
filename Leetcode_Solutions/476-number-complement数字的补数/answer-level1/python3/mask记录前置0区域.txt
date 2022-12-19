### 解题思路
1&0 -> 0
1^x, change x; 0^x, not change x

### 代码

```python3
class Solution:
    def findComplement(self, num: int) -> int:
        mask = ~0 # 11111111
        while mask&num != 0: # 11111111 00000101 -> << 3
            mask <<= 1
        return ~num ^ mask # 11111000 ^ 11111010 -> 010
```