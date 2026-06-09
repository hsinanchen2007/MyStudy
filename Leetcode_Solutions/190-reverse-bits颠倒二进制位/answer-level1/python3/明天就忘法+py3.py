### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reverseBits(self, n: int) -> int:
        res=0
        for i in range(32):
            m=n&1
            n>>=1
            res|=m<<(31-i)
        return res
```