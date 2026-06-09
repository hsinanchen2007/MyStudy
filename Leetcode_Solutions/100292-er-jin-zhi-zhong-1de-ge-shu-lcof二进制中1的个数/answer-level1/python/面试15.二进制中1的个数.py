### 解题思路
转换成二进制后，判断二进制中1的个数。

### 代码

```python3
class Solution:
    def hammingWeight(self, n: int) -> int:
        nbin = '{:b}'.format(n)   #将整数表示成二进制的字符串形式
        nl = [int(i) for i in nbin]
        return sum(nl)
```