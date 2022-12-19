### 解题思路

### 代码

```python3
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        b_N = '{:b}'.format(N)
        lb_N = list(b_N)
        for i in range(0, len(lb_N)):
            lb_N[i] = '0' if lb_N[i] == '1' else '1'
        return int(''.join(lb_N), 2)
```