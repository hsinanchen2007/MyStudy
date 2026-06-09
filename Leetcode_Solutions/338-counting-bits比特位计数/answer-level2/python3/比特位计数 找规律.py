### 解题思路
base为基 = 2^i = [1, 2, 4, 8, 16....]
每个num的二进制即为其所在区间的下界(base)加上(num-base)的二进制
比如12二进制为1100 = bin(base)+bin(12-base) = bin(8) + bin(4) = 1000 + 100 = 1100

### 代码

```python3
class Solution:
    def countBits(self, num: int) -> List[int]:
        res = [0]
        for i in range(1, num+1):
            base = 2**(i-1)
            for j in range(base, 2**i):
                if j>num: return res
                res.append(res[j-base]+1)
        return res # num==0的特例
```