### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def binaryGap(self, N: int) -> int:
        
        A = [i for i in range(32) if (N >> i) & 1]
        if len(A) < 2:
            return 0

        return max(A[idx]-A[idx-1] for idx in range(1, len(A)))
```