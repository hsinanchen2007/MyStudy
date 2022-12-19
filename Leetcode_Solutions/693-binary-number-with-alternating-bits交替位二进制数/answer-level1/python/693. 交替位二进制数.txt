### 解题思路

### 代码

```python3
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        nb = '{:b}'.format(n)
        for i in range(0, len(nb)-1):
            if nb[i] == nb[i+1]:
                return False
        return True

```