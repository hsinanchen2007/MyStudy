### 解题思路

### 代码

```python3
class Solution:
    def binaryGap(self, N: int) -> int:
        bs = list('{:b}'.format(N))
        max = 0
        l1 = bs.index('1')
        while '1' in bs:
            bs.pop(l1)
            if '1' not in bs: break
            l2 = bs.index('1')
            d = l2 - l1 + 1
            l1 = l2
            if d > max: max = d
        return max

```