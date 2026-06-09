### 解题思路
`bin()` 将整数转化为二进制数，然后计算二进制中 `1` 的个数即可。

### 代码

```python
class Solution:
    def hammingWeight(self, n: int) -> int:
        return bin(n).count('1')
```