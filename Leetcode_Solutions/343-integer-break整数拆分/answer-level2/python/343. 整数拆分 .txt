### 解题思路
对于大于3的数，若想和的积最大，最终都需要拆成m个2，n个3的形式，根据余数，判断正数能够拆分成3和2的个数

### 代码

```python
class Solution(object):
    def integerBreak(self, n):
        if n == 2:return 1
        if n == 3:return 2
        mod = n % 3 #找到余数
        int_n = n // 3 # 包含几个3
        if mod == 0:
            return 3 ** int_n
        if mod == 2:
            return (3 ** int_n) * 2
        if mod == 1:
            return (3 ** (int_n - 1)) * 4
```