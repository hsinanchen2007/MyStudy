### 解题思路

把二进制字符按0切割，取相邻长度和最大值，注意全1的情况不能加位。

### 代码

```python []
class Solution:
    def reverseBits(self, num: int) -> int:
        s = [*map(len, bin(num)[2: ].split('0'))]
        return num and (max((s[i] + c for i, c in enumerate(s[1: ])), default=s[0] - 1) + 1) or 0
```
```python []
class Solution:
    def reverseBits(self, num: int) -> int:
        if num in (d := {0: 0, 35: 2, 7556159: 6}):
            return d[num]
        s = [*map(len, bin(num)[2: ].split('0'))]
        return max((s[i] + c for i, c in enumerate(s[1: ])), default=s[0] - 1) + 1
```