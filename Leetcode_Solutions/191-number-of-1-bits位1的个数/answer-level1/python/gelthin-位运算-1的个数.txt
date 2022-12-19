### 解题思路
之前在哪里看到 python3 的位运算似乎有一点特殊。不能靠一直左右移动，来判定。

### 代码

```python3
class Solution:
    def hammingWeight(self, n: int) -> int:
        # 位运算 无符号的整数
        res = 0
        while n>0:
            res += n&1
            n = n>>1
        return res
```