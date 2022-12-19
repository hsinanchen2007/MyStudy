### 解题思路
要是有大神能给我讲讲这是个什么思路就好了

### 代码

```
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        if N == 0:
            return 1
        
        i = 1
        while i <= N:
            i *= 2
        
        return i-N-1
```