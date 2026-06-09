### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def cuttingRope(self, n: int) -> int:
        res = 1
        if n==2 or n==3:
            return n-1
        while n>4:
            n -= 3
            res *= 3
        return res*n
```
明显知道，每次剪去3是最大的，除了在长度对于4的时候，2*2>3*1
因此，长度在4以上的，都剪开，小于、等于4的不要剪开。这样贪心的解法是最优的。